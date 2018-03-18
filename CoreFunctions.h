#ifndef START
#include "Graphics.h"
#include "Audio.h"
#include <stdio.h>
#include <Math.h>
#include "ColGen.h"
#include "Variables.h"
#endif

void CreateAIPoints()
{
	////////

	points[maxPoint].x = 3150;
	points[maxPoint].y = 1540;
	maxPoint++;

	points[maxPoint].x = 3150;
	points[maxPoint].y = 1840;
	maxPoint++;

	////////

	points[maxPoint].x = 3130;
	points[maxPoint].y = 1940;
	maxPoint++;

	points[maxPoint].x = 3070;
	points[maxPoint].y = 2000;
	maxPoint++;

	////////

	points[maxPoint].x = 3000;
	points[maxPoint].y = 2040;
	maxPoint++;
	
	points[maxPoint].x = 2700;
	points[maxPoint].y = 2040;
	maxPoint++;

	points[maxPoint].x = 2400;
	points[maxPoint].y = 2040;
	maxPoint++;
	
	points[maxPoint].x = 2100;
	points[maxPoint].y = 2040;
	maxPoint++;
		
	points[maxPoint].x = 1800;
	points[maxPoint].y = 2040;
	maxPoint++;

	points[maxPoint].x = 1500;
	points[maxPoint].y = 2040;
	maxPoint++;
	
	points[maxPoint].x = 1200;
	points[maxPoint].y = 2040;
	maxPoint++;

			//////////////

	
	points[maxPoint].x = 1147;
	points[maxPoint].y = 2000;
	maxPoint++;

	points[maxPoint].x = 1104;
	points[maxPoint].y = 1940;
	maxPoint++;

	
	////////////

	points[maxPoint].x = 1070;
	points[maxPoint].y = 1840;
	maxPoint++;

	points[maxPoint].x = 1070;
	points[maxPoint].y = 1540;
	maxPoint++;

	points[maxPoint].x = 1070;
	points[maxPoint].y = 1240;
	maxPoint++;


		//////////////

	points[maxPoint].x = 1104;
	points[maxPoint].y = 1185;
	maxPoint++;

	points[maxPoint].x = 1147;
	points[maxPoint].y = 1125;
	maxPoint++;


////////////


	points[maxPoint].x = 1200;
	points[maxPoint].y = 1085;
	maxPoint++;

	points[maxPoint].x = 1500;
	points[maxPoint].y = 1085;
	maxPoint++;

	points[maxPoint].x = 1800;
	points[maxPoint].y = 1085;
	maxPoint++;

	points[maxPoint].x = 2100;
	points[maxPoint].y = 1085;
	maxPoint++;

	points[maxPoint].x = 2400;
	points[maxPoint].y = 1085;
	maxPoint++;

	points[maxPoint].x = 2700;
	points[maxPoint].y = 1085;
	maxPoint++;

	points[maxPoint].x = 3000;
	points[maxPoint].y = 1085;
	maxPoint++;

	//////////////

	points[maxPoint].x = 3070;
	points[maxPoint].y = 1125;
	maxPoint++;

	points[maxPoint].x = 3130;
	points[maxPoint].y = 1185;
	maxPoint++;

	//////////////

	points[maxPoint].x = 3150;
	points[maxPoint].y = 1240;
	maxPoint++;

	for (int i = 0; i < maxPoint; i++)
	{
		points[i].x=points[i].x*1333/955-817;
		points[i].y=points[i].y*1333/955-555;
	}
	inimigo1.x = points[0].x;
	//inimigo1.y = points[0].y - 200;
}

void CreateAIPoints2()
{
	maxPoint = 0;

		 points2[maxPoint].x = 3537;
	points2[maxPoint].y = 1254;
	 maxPoint++;

	points2[maxPoint].x = 3537;
	 points2[maxPoint].y = 1316;
	 maxPoint++;


	points2[maxPoint].x = 3537;
	 points2[maxPoint].y = 1442;
	 maxPoint++;

	points2[maxPoint].x = 3537;
	 points2[maxPoint].y = 1522;
	 maxPoint++;

	points2[maxPoint].x = 3537;
	 points2[maxPoint].y = 1666;
	 maxPoint++;

	points2[maxPoint].x = 3537;
	 points2[maxPoint].y = 1718;
	 maxPoint++;

	points2[maxPoint].x = 3537;
	 points2[maxPoint].y = 1878;
	 maxPoint++;

	points2[maxPoint].x = 3529;
	 points2[maxPoint].y = 2014;
	 maxPoint++;

	points2[maxPoint].x = 3485;
	 points2[maxPoint].y = 2118;
	 maxPoint++;

	points2[maxPoint].x = 3453;
	 points2[maxPoint].y = 2154;
	 maxPoint++;

	points2[maxPoint].x = 3373;
	 points2[maxPoint].y = 2190;
	 maxPoint++;

	points2[maxPoint].x = 3285;
	 points2[maxPoint].y = 2110;
	 maxPoint++;

	points2[maxPoint].x = 3097;
	 points2[maxPoint].y = 2110;
	 maxPoint++;

	points2[maxPoint].x = 2849;
	 points2[maxPoint].y = 2110;
	 maxPoint++;

	points2[maxPoint].x = 2645;
	 points2[maxPoint].y = 2110;
	 maxPoint++;

	points2[maxPoint].x = 2521;
	 points2[maxPoint].y = 2110;
	 maxPoint++;

	points2[maxPoint].x = 2525;
	 points2[maxPoint].y = 2110;
	 maxPoint++;

	points2[maxPoint].x = 2385;
	 points2[maxPoint].y = 2114;
	 maxPoint++;

	points2[maxPoint].x = 2385;
	 points2[maxPoint].y = 2062;
	 maxPoint++;

	points2[maxPoint].x = 2369;
	 points2[maxPoint].y = 1970;
	 maxPoint++;

	points2[maxPoint].x = 2333;
	 points2[maxPoint].y = 1866;
	 maxPoint++;

	points2[maxPoint].x = 2285;
	 points2[maxPoint].y = 1746;
	 maxPoint++;

	points2[maxPoint].x = 2185;
	 points2[maxPoint].y = 1674;
	 maxPoint++;

	points2[maxPoint].x = 2033;
	 points2[maxPoint].y = 1674;
	 maxPoint++;

	points2[maxPoint].x = 1909;
	 points2[maxPoint].y = 1674;
	 maxPoint++;

	points2[maxPoint].x = 1817;
	 points2[maxPoint].y = 1674;
	 maxPoint++;

	points2[maxPoint].x = 1737;
	 points2[maxPoint].y = 1766;
	 maxPoint++;

	points2[maxPoint].x = 1693;
	 points2[maxPoint].y = 1842;
	 maxPoint++;

	points2[maxPoint].x = 1669;
	 points2[maxPoint].y = 1986;
	 maxPoint++;

	points2[maxPoint].x = 1645;
	 points2[maxPoint].y = 2070;
	 maxPoint++;

	points2[maxPoint].x = 1613;
	 points2[maxPoint].y = 2126;
	 maxPoint++;

	points2[maxPoint].x = 1561;
	 points2[maxPoint].y = 2162;
	 maxPoint++;

	points2[maxPoint].x = 1485;
	 points2[maxPoint].y = 2206;
	 maxPoint++;

	points2[maxPoint].x = 1453;
	 points2[maxPoint].y = 2206;
	 maxPoint++;

	points2[maxPoint].x = 1381;
	 points2[maxPoint].y = 2206;
	 maxPoint++;

	points2[maxPoint].x = 1105;
	 points2[maxPoint].y = 2206;
	 maxPoint++;

	points2[maxPoint].x = 785;
	 points2[maxPoint].y = 2210;
	 maxPoint++;

	points2[maxPoint].x = 677;
	 points2[maxPoint].y = 2218;
	 maxPoint++;

	points2[maxPoint].x = 633;
	 points2[maxPoint].y = 2194;
	 maxPoint++;

	points2[maxPoint].x = 561;
	 points2[maxPoint].y = 2126;
	 maxPoint++;

	points2[maxPoint].x = 529;
	 points2[maxPoint].y = 2078;
	 maxPoint++;

	points2[maxPoint].x = 501;
	 points2[maxPoint].y = 1962;
	 maxPoint++;

	points2[maxPoint].x = 497;
	 points2[maxPoint].y = 1758;
	 maxPoint++;

	points2[maxPoint].x = 497;
	 points2[maxPoint].y = 1358;
	 maxPoint++;

	points2[maxPoint].x = 497;
	 points2[maxPoint].y = 1022;
	 maxPoint++;

	points2[maxPoint].x = 521;
	 points2[maxPoint].y = 914;
	 maxPoint++;

	points2[maxPoint].x = 561;
	 points2[maxPoint].y = 858;
	 maxPoint++;

	points2[maxPoint].x = 617;
	 points2[maxPoint].y = 830;
	 maxPoint++;

	points2[maxPoint].x = 689;
	 points2[maxPoint].y = 810;
	 maxPoint++;

	points2[maxPoint].x = 777;
	 points2[maxPoint].y = 802;
	 maxPoint++;

	points2[maxPoint].x = 921;
	 points2[maxPoint].y = 802;
	 maxPoint++;

	points2[maxPoint].x = 1413;
	 points2[maxPoint].y = 802;
	 maxPoint++;

	points2[maxPoint].x = 1517;
	 points2[maxPoint].y = 802;
	 maxPoint++;

	points2[maxPoint].x = 1613;
	 points2[maxPoint].y = 890;
	 maxPoint++;

	points2[maxPoint].x = 1661;
	 points2[maxPoint].y = 1010;
	 maxPoint++;

	points2[maxPoint].x = 1701;
	 points2[maxPoint].y = 1182;
	 maxPoint++;

	points2[maxPoint].x = 1725;
	 points2[maxPoint].y = 1226;
	 maxPoint++;

	points2[maxPoint].x = 1813;
	 points2[maxPoint].y = 1318;
	 maxPoint++;

	points2[maxPoint].x = 1909;
	 points2[maxPoint].y = 1366;
	 maxPoint++;

	points2[maxPoint].x = 2069;
	 points2[maxPoint].y = 1370;
	 maxPoint++;

	points2[maxPoint].x = 2193;
	 points2[maxPoint].y = 1370;
	 maxPoint++;

	points2[maxPoint].x = 2273;
	 points2[maxPoint].y = 1226;
	 maxPoint++;

	points2[maxPoint].x = 2337;
	 points2[maxPoint].y = 1142;
	 maxPoint++;

	points2[maxPoint].x = 2357;
	 points2[maxPoint].y = 1006;
	 maxPoint++;

	points2[maxPoint].x = 2394;
	 points2[maxPoint].y = 880;
	 maxPoint++;

	points2[maxPoint].x = 2427;
	 points2[maxPoint].y = 830;
	 maxPoint++;

	points2[maxPoint].x = 2537;
	 points2[maxPoint].y = 806;
	 maxPoint++;

	points2[maxPoint].x = 2673;
	 points2[maxPoint].y = 798;
	 maxPoint++;

	points2[maxPoint].x = 2926;
	 points2[maxPoint].y = 798;
	 maxPoint++;

	points2[maxPoint].x = 3333;
	 points2[maxPoint].y = 798;
	 maxPoint++;

	points2[maxPoint].x = 3433;
	 points2[maxPoint].y = 838;
	 maxPoint++;

	points2[maxPoint].x = 3489;
	 points2[maxPoint].y = 910;
	 maxPoint++;

	points2[maxPoint].x = 3521;
	 points2[maxPoint].y = 978;
	 maxPoint++;

	points2[maxPoint].x = 3537;
	 points2[maxPoint].y = 1014;
	 maxPoint++;

	points2[maxPoint].x = 3537;
	 points2[maxPoint].y = 1086;
	 maxPoint++;

	points2[maxPoint].x = 3537;
	 points2[maxPoint].y = 1182;
	 maxPoint++;

	 for (int in = 0; in < maxPoint; in++)
	{
		points2[in].x = points2[in].x-30;
		points2[in].y = points2[in].y*768/678-150;
	}
}

void Teclado(int key, int state, int x, int y)
{
	Carro* control = &player;  //Caso o objetivo seja controlar outro carro, mudar aqui
	//Carro* control = &inimigo1;

	if (state == KEY_STATE_DOWN)
	{
		if (key == KEY_LEFT)
		{
			p.left = true;
			if (p.right == false)
				(*control).direction = Esquerda;
		}
		if (key == KEY_RIGHT)
		{
			p.right = true;
			if (p.left == false)
				(*control).direction = Direita;
		}
		if (key == KEY_UP)
		{
			p.up = true;
			(*control).aceleration = Acelerando;
		}
		if (key == KEY_DOWN)
		{
			p.down = true;
			if ((*control).aceleration != Acelerando)
				(*control).aceleration = Re;
		}
	}
	else
	{
		if (key == KEY_LEFT)
		{
			p.left = false;
			if (p.right == true)
				(*control).direction = Direita;
			else
				(*control).direction = Parado;
		}
		if (key == KEY_RIGHT)
		{
			p.right = false;
			if (p.left == true)
				(*control).direction = Esquerda;
			else
				(*control).direction = Reto;
		}
		if (key == KEY_UP)
		{
			p.up = false;
			if (p.down == true)
				(*control).aceleration = Re;
			else
				(*control).aceleration = Parado;
		}
		if (key == KEY_DOWN)
		{
			p.down = false;
			if ((*control).aceleration != Acelerando)
				(*control).aceleration = Parado;
		}
	}
	if ((key == '-' ) && (state == KEY_STATE_UP))
		_debug_mode = !_debug_mode;
	if ((key == '=' ) && (state == KEY_STATE_UP))
		_auto = !_auto;
	if ((key == ')' ) && (state == KEY_STATE_UP))
	{
		ResetVariables();
		CreateAIPoints2();
		_gamescreen = 2;
		_racestart = 3000;
		_race = false;
		_gtimer = 0;
		_xscale = 1024/731.53;
		_yscale = 768/568.57;
		player.x = 3635;
		player.y = 1126;
		inimigo1.x = 3546;
		inimigo1.y = 1126;
	}
	if ((key == '3' ) && (state == KEY_STATE_UP))
		player.x = 0;
	if ((key == '4' ) && (state == KEY_STATE_UP))
		player.y = 0;
	if ((key == '1' ) && (state == KEY_STATE_UP))
		player.x += 100;
	if ((key == '2' ) && (state == KEY_STATE_UP))
		player.y += 100;
	if ((key == 'q' ) && (state == KEY_STATE_UP))
		player.x -= 100;
	if ((key == 'w' ) && (state == KEY_STATE_UP))
		player.y -= 100;
	if (key == 27) //esc
	{
		for (int a = 0; a < 3; a++)
			for (int b = 0; b < 3; b++)
				_saveplayerscore[a][b] = player.lapTime[a][b];
		_save = 1;
		ResetVariables();					
		_gamescreen = 0;
		_racestart = 0;
		_race = false;
		_xscale = 1024 / 1432.0;
		_yscale = 768 / 1075.0;
		_gtimer = 0;
	}
}

void JogarClick(int button, int state, int x, int y)
{
	if ((button == MOUSE_LEFT_BUTTON) && (state == MOUSE_STATE_DOWN) && _gamescreen == 0)
	{
		if (_msg == 0)
		{
		_msg = 1;
		}
	}
}

void ContinuarClick(int button, int state, int x, int y)
{
	if ((button == MOUSE_LEFT_BUTTON) && (state == MOUSE_STATE_DOWN) && _gamescreen == 0)
	{
		if (_msg == 2)
		{
		_gamescreen = 1;
		//_race = true;
		_racestart = 3000;
		_msg = 0;
		}
		else if (_msg == 1)
		{
		_msg = 2;
		}
	}
}

void PlacarClick(int button, int state, int x, int y)
{
	if ((button == MOUSE_LEFT_BUTTON) && (state == MOUSE_STATE_DOWN) && _gamescreen == 0 && _msg == 0)
	{
		_gamescreen = -2;
	}
}

void MusicaPauseClick(int button, int state, int x, int y)
{
	if ((button == MOUSE_LEFT_BUTTON) && (state == MOUSE_STATE_DOWN))
		musica.state = Trocar;
}

void ImageAudioLoadSet()
{
	/*<imagens index>*/
	png_fundo.LoadPNGImage("Imagens\\png_fundo.png");
	png_musica.LoadPNGImage("Imagens\\png_musica.png");
	png_som.LoadPNGImage("Imagens\\png_som.png");
	png_botao_jogar.LoadPNGImage("Imagens\\png_botao_jogar.png");
	png_botao_placar.LoadPNGImage("Imagens\\png_botao_placar.png");
	png_botao_continuar.LoadPNGImage("Imagens\\png_botao_continuar.png");
	png_paper1.LoadPNGImage("Imagens\\png_paper1.png");
	png_instrucoes.LoadPNGImage("Imagens\\png_instrucoes.png");
	png_pista1.LoadPNGImage("Imagens\\png_pista1.png");
	png_pista2.LoadPNGImage("Imagens\\png_pista2.png");
	png_pista3.LoadPNGImage("Imagens\\png_pista3.png");
	png_carro1.LoadPNGImage("Imagens\\png_carro1.png");
	png_inimigo1.LoadPNGImage("Imagens\\png_inimigo1.png");
	png_sinal1.LoadPNGImage("Imagens\\png_sinal1.png");
	png_sinal2.LoadPNGImage("Imagens\\png_sinal2.png");
	png_sinal3.LoadPNGImage("Imagens\\png_sinal3.png");
	png_sinal4.LoadPNGImage("Imagens\\png_sinal4.png");
	/*</imagens index>*/

	/*<sons index>*/
	musica_1.LoadAudio("Sons\\mp3_musica1.mp3");
	som_1.LoadAudio("Sons\\mp3_som1.mp3");
	/*</sons index>*/

	/*<set index>*/
	png_musica.SetPosition(990, 720, 23, 23);
	png_musica.SetOnClick(MusicaPauseClick);
	png_botao_jogar.SetPosition(70, 470, 224, 80);
	png_botao_jogar.SetOnClick(JogarClick);
	png_botao_placar.SetPosition(70, 380, 224, 80);
	png_botao_placar.SetOnClick(PlacarClick);
	png_botao_continuar.SetPosition(70, 70, 224, 80);
	png_botao_continuar.SetOnClick(ContinuarClick);
	/*</set index>*/
}