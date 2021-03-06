/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if( wnd.kbd.KeyIsPressed( VK_UP ) )
	{
		--yPos;
	}
	if( wnd.kbd.KeyIsPressed( VK_DOWN ) )
	{
		++yPos;
	}
	if( wnd.kbd.KeyIsPressed( VK_LEFT ) )
	{
		--xPos;
	}
	if( wnd.kbd.KeyIsPressed( VK_RIGHT ) )
	{
		++xPos;
	}
	if( wnd.kbd.KeyIsPressed( 'W' ) )
	{
		--height;
	}
	if( wnd.kbd.KeyIsPressed( 'S' ) )
	{
		++height;
	}
	if( wnd.kbd.KeyIsPressed( 'A' ) )
	{
		--width;
	}
	if( wnd.kbd.KeyIsPressed( 'D' ) )
	{
		++width;
	}
}

void Game::ComposeFrame()
{
	
	int startX = 20;
	int startY = 20;
	int endX = gfx.ScreenWidth - 20;
	int endY = gfx.ScreenHeight - 20;
	int startingValues[4];
	int repeat = 21;
	startingValues[0] = startX;
	startingValues[1] = startY;
	startingValues[2] = endX;
	startingValues[3] = endY;

	for (int a = 0; a < repeat; a++)
	{
		for (int i = startY; i < endY; ++i)
		{
			for (int j = startX; j < endX; ++j)
			{
	
				if (i == startY || i == endY - 1)
				{
					gfx.PutPixel(j, i, 255, 255, 255);
				}
				else if (j == startX || j == endX - 1)
				{
					gfx.PutPixel(j, i, 255, 255, 255);
				}
	
	
			}
		}
		--startX;
		--startY;
		++endX;
		++endY;
	}

	startX = startingValues[0];
	startY = startingValues[1];
	endX = startingValues[2];
	endY = startingValues[3];

}
