#ifndef START
#include "Graphics.h"
#include "Audio.h"
#include <stdio.h>
#include <Math.h>
#include "ColGen.h"
#include "Variables.h"
#include "CoreFunctions.h"
#include "MainFunctions.h"
#include "Draw.h"
#endif

/*<botões de som>*/
	graphics.DrawImage2D(990, 720, 23, 23, png_musica);
	graphics.DrawImage2D(930, 720, 55, 25, png_som);

	if (musica.state == Tocar)
	{
		if(!musica_1.IsPlaying())
		{
			musica_1.Stop();
			musica_1.Play();
		}
	}
	else if(musica.state == Trocar)
	{
		if (musica_1.IsPlaying() == true)
		{
			musica_1.Pause();
			musica.state = Parar;
		}
		else
		{
			musica_1.Play();
			musica.state = Tocar;
		}
	}
	else if (musica.state == Parar)
	{
		graphics.SetLineWidth(12);
		graphics.SetColor(80, 0, 0);
		graphics.DrawLine2D(990, 720, 1013, 743);
	}
	/*</botões de som>*/