#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "olcConsoleGameEngine.h";

class OneLoneCoder_UltimateFPS : public olcConsoleGameEngine {
public:
	OneLoneCoder_UltimateFPS() {
		m_sAppName = L"ultimate First Person Shooter";
	}
	virtual bool OnUserCreate() {
		map += L"##########......";
		map += L"#...............";
		map += L"#........#######";
		map += L"#..............#";
		map += L"#......##......#";
		map += L"#......##......#";
		map += L"#..............#";
		map += L"###............#";
		map += L"##.............#";
		map += L"#......####..###";
		map += L"#......#.......#";
		map += L"#......#.......#";
		map += L"#..............#";
		map += L"#......#########";
		map += L"#..............#";
		map += L"################";

		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime) {
		// Controlls
		// Handle CCW Rotation
		if (m_keys[L'A'].bHeld)
			fPlayerA -= (fSpeed * 0.75f) * fElapsedTime;

		if (m_keys[L'D'].bHeld)
			fPlayerA += (fSpeed * 0.75f) * fElapsedTime;

		if (m_keys[L'W'].bHeld) {
			fPlayerX += sinf(fPlayerA) * 5.0f * fElapsedTime;
			fPlayerY += cosf(fPlayerA) * 5.0f * fElapsedTime;

			if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#') {
				fPlayerX -= sinf(fPlayerA) * 5.0f * fElapsedTime;
				fPlayerY -= cosf(fPlayerA) * 5.0f * fElapsedTime;
			}
		}

		if (m_keys[L'S'].bHeld) {
			fPlayerX -= sinf(fPlayerA) * 5.0f * fElapsedTime;
			fPlayerY -= cosf(fPlayerA) * 5.0f * fElapsedTime;

			if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#') {
				fPlayerX += sinf(fPlayerA) * 5.0f * fElapsedTime;
				fPlayerY += cosf(fPlayerA) * 5.0f * fElapsedTime;
			}
		}

		for (int x = 0; x < ScreenWidth(); x++) {
			// For each column, calculate the projected ray angle into world space
			float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)ScreenWidth()) * fFOV;

			float fDistanceToWall = 0;
			bool bHitWall = false;

			bool bBoundary = false;

			float fEyeX = sinf(fRayAngle); // Unit vector for ray in player space
			float fEyeY = cosf(fRayAngle);

			while (!bHitWall && fDistanceToWall < fDepth) {


				fDistanceToWall += 0.1f;

				int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
				int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

				// Test if ray is our of bounds
				if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight) {
					bHitWall = true;      // Just set distance to maximum depth
					fDistanceToWall = fDepth;
				}
				else {
					// Ray is inbounds so test to see if the ray cell is a wall block
					if (map[nTestY * nMapWidth + nTestX] == '#') {
						bHitWall = true;

						vector<pair<float, float>> p; // distance, dot

						for (int tx = 0; tx < 2; tx++) {
							for (int ty = 0; ty < 2; ty++) {
								float vy = (float)nTestY + ty - fPlayerY;
								float vx = (float)nTestX + tx - fPlayerX;
								float d = sqrt(vx * vx + vy * vy);
								float dot = (fEyeX * vx / d) + (fEyeY * vy / d);
								p.push_back(make_pair(d, dot));
							}

							// Sort Pairs from closest to farthest
							sort(p.begin(), p.end(), [](const pair<float, float>& left, const pair<float, float>& right) {return left.first < right.first; });

							float fBound = 0.01;
							if (acos(p.at(0).second) < fBound) bBoundary = true;
							if (acos(p.at(1).second) < fBound) bBoundary = true;
							//if (acos(p.at(2).second) < fBound) bBoundary = true;
						}
					}
				}
			}

			// Calculate distance to ceiling and floor
			int nCeiling = (float)(ScreenHeight() / 2.0) - ScreenHeight() / ((float)fDistanceToWall);
			int nFloor = ScreenHeight() - nCeiling;

			short nShade = ' ';

			if (fDistanceToWall <= fDepth / 4.0f)     nShade = 0x2588;    // very close
			else if (fDistanceToWall < fDepth / 3.0f) nShade = 0x2593;
			else if (fDistanceToWall < fDepth / 2.0f) nShade = 0x2592;
			else if (fDistanceToWall < fDepth)        nShade = 0x2591;
			else                                      nShade = ' ';

			if (bBoundary)              nShade = ' '; // Black it out

			for (int y = 0; y < ScreenHeight(); y++) {
				if (y < nCeiling)
					Draw(x, y, L' ');
				else if (y > nCeiling && y <= nFloor)
					Draw(x, y, nShade);
				else {
					float b = 1.0f - (((float)y - ScreenHeight() / 2.0f) / ((float)ScreenHeight() / 2.0f));
					if (b < 0.25)        nShade = '#';
					else if (b < 0.5)    nShade = 'X';
					else if (b < 0.75)   nShade = '.';
					else if (b < 0.9)    nShade = '-';
					else if (b < 1.0)    nShade = ' ';
					Draw(x, y, nShade);
				}
			}
		}

		/* Display Stats
		swprintf_s(screen, 40, L"X=%3.2f, Y=%3.2f, A=%3.2f FPS=%3.2f ", fPlayerX, fPlayerY, fPlayerA, 1.0f / fElapsedTime);



		screen[nScreenWidth * nScreenHeight - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth* nScreenHeight, { 0,0 }, & dwBytesWritten);*/


		// Display Map
		for (int nx = 0; nx < nMapWidth; nx++)
			for (int ny = 0; ny < nMapWidth; ny++)
				Draw(nx + 1, ny + 1, map[ny * nMapWidth + nx]);
		Draw(1 + (int)fPlayerY, 1 + (int)fPlayerX, L'P');

		return true;

		
	}
private:
	float fPlayerX = 14.7f;
	float fPlayerY = 5.09f;
	float fPlayerA = 0.0f;

	wstring map;

	int nMapHeight = 16;
	int nMapWidth = 16;

	float fFOV = 3.14159f / 4.0f;
	float fDepth = 16.0f;
	float fSpeed = 5.0f;
};


int main() {
	OneLoneCoder_UltimateFPS game;
	game.ConstructConsole(320, 240, 4, 4);
	game.Start();

		


	return 0;
}