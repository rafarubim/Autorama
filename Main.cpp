#define START

#include "Graphics.h"
#include "Audio.h"
#include <stdio.h>
#include <Math.h>
#include "ColGen.h"

#define Pi 3.14159265358979323846

#include "Variables.h" //Define as estruturas, variáveis e cria a função ResetVariables

#include "CoreFunctions.h" //Define as funções de teclado, mouse e que serão usadas no "int main()"

#include "MainFunctions.h" //Define as funções que serão usadas no Main Loop

void MainLoop()
{
    float timer = graphics.GetElapsedTime();

    if (_race && _gamescreen != -1)
    {
        UpdateCar(timer,&player);
		UpdateAI(timer,&inimigo1);
    }

	Draw(); //Desenha os elementos da tela (dependendo da gamescreen)

	Sound(); //Controla os sons do jogo

	if (_gamescreen == -1)
	{
		countdown -= 1;
		graphics.DrawImage2D(0, 0, 1024, 768, png_loading);
		if (countdown < 0)
		{
			CreateAIPoints();
			ImageAudioLoadSet();
			ColGen cg;
			map1_col = cg.Load("fase1.txt");
			ColGen cg2;
			map2_col = cg2.Load("fase2.txt");
			_gamescreen = 0;
		}
	}

	if (_gamescreen != -2 && _gamescreen != 0 && _gamescreen != -1 && _race == false)
	{
		_racestart -= 5;
		if (_racestart >= 2000)
			graphics.DrawImage2D(270,500,150,150,png_sinal1);
		else if (_racestart >= 1000)
			graphics.DrawImage2D(270,500,150,150,png_sinal2);
		else if (_racestart >= 0)
			graphics.DrawImage2D(270,500,150,150,png_sinal3);
		if (_racestart <= 0)
		{
			_race = true;
			_signkeep = 1000;
		}
	}
	if (_signkeep > 0)
	{
		_signkeep -= 5;
		graphics.DrawImage2D(270, 500, 150, 150, png_sinal4);
		graphics.SetColor(0, 255, 0);
		graphics.DrawText2D(325,480,"Go!");
	}

	if (_race)
	{
		GameAI();
		_gtimer += timer;
	}
}

int main(void)
{
	ResetVariables();

	musica.state = Parar;

	FirstScore();

	graphics.CreateMainWindow(1024, 768, "Dream Race");

	png_loading.LoadPNGImage("Imagens\\png_loading.png");

	graphics.SetKeyboardInput(Teclado);

	graphics.SetBackgroundColor(255,255,255);

	graphics.SetMainLoop(MainLoop);

	graphics.StartMainLoop();

	return 0;
}

