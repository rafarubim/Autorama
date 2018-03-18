#ifndef START
#include "Graphics.h"
#include "Audio.h"
#include <stdio.h>
#include <Math.h>
#include "ColGen.h"
#include "Variables.h"
#include "CoreFunctions.h"
#include "MainFunctions.h"
#endif

if (_gamescreen == 0)
	{
	/*<index>*/
		graphics.DrawImage2D(0, 0, 1024,768, png_fundo);
		graphics.DrawImage2D(70, 470, 224, 80, png_botao_jogar);
		graphics.DrawImage2D(70, 380, 224, 80, png_botao_placar);
	/*</index>*/
	}
	else if (_gamescreen == 1 && _pause == false)
	{
		graphics.DrawImage2D(0, 0, 1024, 768, -835+player.x, -537.6-player.y, 1433.6, 1075.2, png_pista1);

		graphics.SetColor(100,0,0);
		graphics.DrawText2D(30,660,"%f",player.speed);

		graphics.RotateBegin(-90+player.rotation*180/Pi);
		graphics.DrawImage2D(500, 300, 200, 200, png_carro1);
		graphics.RotateEnd();

		Position inimigo1_pos = CarPos(&inimigo1, xscale, yscale);
		graphics.RotateBegin(-90+inimigo1.rotation*180/Pi);
		graphics.DrawImage2D(inimigo1_pos.x, inimigo1_pos.y, 200, 200, png_inimigo1);
		graphics.RotateEnd();

	}