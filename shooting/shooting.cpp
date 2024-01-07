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

			float fStepSize = 0.01f;
			float fDistanceToWall = 0.0f;

			bool bHitWall = false;
			bool bBoundary = false;

			float fEyeX = sinf(fRayAngle); // Unit vector for ray in player space
			float fEyeY = cosf(fRayAngle);

			float fSampleX = 0.0f;
			float fSampleY = 0.0f;

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

						//Determine where ray has hit wall. Break Block boundary
						float fBlockMidX = (float)nTestX + 0.5f;
						float fBlockMidY = (float)nTestY + 0.5f;

						float fTestPointX = fPlayerX + fEyeX * fDistanceToWall;
						float fTestPointY = fPlayerY + fEyeY * fDistanceToWall;

						float fTestAngle = atan2f((fTestPointY - fBlockMidY), (fTestPointX - fBlockMidX));

						if (fTestAngle >= -3.14159f * 0.25f && fTestAngle < 3.14159f * 0.25f)
							fSampleX = fTestPointY - (float)nTestY;

						if (fTestAngle >= 3.14159f * 0.25f && fTestAngle < 3.14159f * 0.75f)
							fSampleX = fTestPointX - (float)nTestX;

						if (fTestAngle >= -3.14159f * 0.25f && fTestAngle < -3.14159f * 0.75f)
							fSampleX = fTestPointX - (float)nTestX;

						if (fTestAngle >= 3.14159f * 0.75f || fTestAngle < -3.14159f * 0.75f)
							fSampleX = fTestPointY - (float)nTestY;
					}
				}
			}

			// Calculate distance to ceiling and floor
			int nCeiling = (float)(ScreenHeight() / 2.0) - ScreenHeight() / ((float)fDistanceToWall);
			int nFloor = ScreenHeight() - nCeiling;


			for (int y = 0; y < ScreenHeight(); y++) {
				if (y < nCeiling)
					Draw(x, y, L' ');
				else if (y > nCeiling && y <= nFloor) {
					if (fDistanceToWall < fDepth) {
						float fSampleY = ((float)y - (float)nCeiling / (float)nFloor - (float)nCeiling);
						//Draw(x, y, spriteWall->SampleGlyph(fSampleX, fSampleY), spriteWall->SampleColour(fSampleX, fSampleY));
					}
					else
						Draw(x, y, PIXEL_SOLID, 0);
					
				}
				else {
					Draw(x, y, PIXEL_SOLID, FG_DARK_GREEN);
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