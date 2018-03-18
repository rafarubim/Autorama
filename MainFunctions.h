#ifndef START
#include "Graphics.h"
#include "Audio.h"
#include <stdio.h>
#include <Math.h>
#include "ColGen.h"
#include "Variables.h"
#include "CoreFunctions.h"
#endif

bool getWrongDir1(float x, float y, float rotation)
{
	while (rotation < 0)
		rotation += 2*Pi;
	float min_rotation = fmod(rotation*1.0,2*Pi);
	if (_gamescreen == 1)
	{
		if (x >= 301 && x <= 3985 && y >= 2200 && y <= 2593 && (min_rotation >= 5*Pi/3 || min_rotation <= Pi/3))
			return 1;
		if (x >= 301 && x <= 3985 && y >= 685 && y <= 1064 && (min_rotation >= 2*Pi/3 && min_rotation <= 4*Pi/3))
			return 1;
		if (x >= 301 && x <= 989 && y >= 1064 && y <= 2200 && (min_rotation >= Pi/6 && min_rotation <= 5*Pi/6))
			return 1;
		if (x >= 3308 && x <= 3985 && y >= 1064 && y <= 2200 && (min_rotation >= 7*Pi/6 && min_rotation <= 11*Pi/6))
			return 1;
	}
	return 0;
}

void lapRefresh(Carro* carro)
{
	if ((*carro).laps >= 1 && (*carro).laps <= 3)
	{
		if ((*carro).lapTime[_gamescreen-1][(*carro).laps-1] == 0)
		{
			if ((*carro).laps >= 2)
				(*carro).lapTime[_gamescreen-1][(*carro).laps-1] = _gtimer-(*carro).lapTime[_gamescreen-1][(*carro).laps-1];
			else
				(*carro).lapTime[_gamescreen-1][(*carro).laps-1] = _gtimer;
		}
	}
}

void controlLaps(Carro* carro)
{
	if (_gamescreen == 1)
	{
		if ((*carro).x >= 3308 && (*carro).x <= 3985 && (*carro).oldFrontY < 1620 && (*carro).y+sin((*carro).rotation)*(*carro).halfwidth >= 1620)
		{
			(*carro).laps += 1;
			lapRefresh(carro);
		}
		else if ((*carro).x >= 3308 && (*carro).x <= 3985 && (*carro).oldFrontY > 1620 && (*carro).y+sin((*carro).rotation)*(*carro).halfwidth <= 1620)
			(*carro).laps -= 1;
	}
}

Position PosInScreen(float px, float py)
{
	Position p;
	if (_gamescreen == 1)
	{
		p.x = (px-player.x+831)*_xscale;//831- 835
		p.y = (py-player.y+559)*_yscale;//559- 519
	}
	else if (_gamescreen == 2)
	{
		p.x = (px-player.x+418+100)*_xscale;//418- 422
		p.y = (py-player.y+234+100)*_yscale;//234- 274
	}
	return p;
}

float cdistance(Position a, Position b){
	return sqrt(pow(b.y - a.y,2) + pow(b.x - a.x,2)) ;
}

Position newPosition(Position p,  float angle, float dist){

	//angle = (angle +90) * PI / 180.0;
	float _sin = sin(angle);
	float _cos = cos(angle);

	Position newP;
	newP.x = (dist  * _cos) + p.x;
	newP.y = (dist  * _sin) + p.y;

	return newP;
}

float getAngle(Position p1, Position p2) //Devolverá ângulo em radianos entre p1 e p2 considerando o círculo trigonométrico, com p1 na origem e p2 na circunferência
{
	float firstquadrantangle = atan2(abs(p2.y - p1.y), abs(p2.x - p1.x));
	if (p2.x - p1.x >= 0) //Se p1 for a origem, p2 estará no:
	{
		if (p2.y - p1.y >= 0)
			return firstquadrantangle; //primeiro quadrante
		else
			return 2*Pi-firstquadrantangle; //quarto quadrante
	}
	else
	{
		if (p2.y - p1.y >= 0)
			return Pi-firstquadrantangle; //segundo quadrante
		else
			return Pi+firstquadrantangle; //terceiro quadrante
	}
}

int getMinorAngleDiffDirection(float angle1, float angle2) //Devolverá 1 se o ângulo1 for mais próximo do ângulo2 pela esquerda e devolverá -1 se for mais próximo pela direita
{
	if (angle1 >= angle2)
	{
		if (angle1-angle2 < Pi)
			return -1;
		else
			return 1;
	}
	else
	{
		if (angle2-angle1 < Pi)
			return 1;
		else
			return -1;
	}
}

float getMinorAngleDiff(float angle1, float angle2) //Devolverá o menor ângulo entre dois ângulos
{
	int teste = getMinorAngleDiffDirection(angle1, angle2);
	if (angle1 >= angle2)
	{
		if (teste == 1)
			return angle2+2*Pi-angle1;
		else
			return angle1-angle2;
	}
	else
	{
		if (teste == 1)
			return angle2-angle1;
		else
			return angle1+2*Pi-angle2;
	}
}

int Colisao_Carro_Fase1(float pos_x, float pos_y)
{
	int pixelX = (int) pos_x;
	int pixelY = (int) pos_y;

	char c = 'P';

	if (pixelX >= 0 && pixelX < 4266 && pixelY >= 0 && pixelY < 3200)
		c = map1_col[3199-pixelY][pixelX];

	//c = 'B';

	return (c == 'B'? 1 : (c == 'V' ? 2 : 0));
}

int Colisao_Carro_Fase2(float pos_x, float pos_y)
{
	int pixelX = (int) pos_x;
	int pixelY = (int) pos_y;

	char c = 'P';

	if (pixelX >= 0 && pixelX < 4000 && pixelY >= 0 && pixelY < 3000)
		c = map2_col[2999-pixelY][pixelX];

	//c = 'B';

	return (c == 'B'? 1 : (c == 'V' ? 2 : 0));
}

int Colisao_Carro_Fase(float pos_x, float pos_y)
{
	int a = 1;
	if (_gamescreen == 1)
		a = Colisao_Carro_Fase1(pos_x, pos_y);
	else if (_gamescreen == 2)
		a = Colisao_Carro_Fase2(pos_x, pos_y);
	return a;
}

float saveTargetDistance = 0;

void GameAI()
{
		Carro* carroIA = &inimigo1;

	if (_debug_mode)
	{
		graphics.SetColor(255,0,0);
	
		if (_gamescreen == 1)
		{
			for(int i = 0; i < maxPoint; i++)
			{
				int px = points[i].x;
				int py = points[i].y;
				Position p = PosInScreen(px, py);
				graphics.FillCircle2D(p.x, p.y, 5, 5);
			}
		}
		else if (_gamescreen == 2)
		{
				for(int i = 0; i < maxPoint; i++)
			{
				int px = points2[i].x;
				int py = points2[i].y;
				Position p = PosInScreen(px, py);
				graphics.FillCircle2D(p.x, p.y, 5, 5);
			}
		}

	}

	Position target;
	if (_gamescreen == 1)
		target = points[nextPoint];
	else if (_gamescreen == 2)
		target = points2[nextPoint];

	Position carroPos;
	carroPos.x = (*carroIA).x;
	carroPos.y = (*carroIA).y;

	float targetDistance = cdistance(target, carroPos);
	if (saveTargetDistance == 0)
		saveTargetDistance = targetDistance;

	Position pointing_at = newPosition(carroPos, (*carroIA).rotation, targetDistance);

	if (_debug_mode)
	{
		Position pos1 = PosInScreen(target.x, target.y);
		graphics.DrawCircle2D(pos1.x, pos1.y, 40);
		Position pos2 = PosInScreen(pointing_at.x, pointing_at.y);
		graphics.DrawCircle2D(pos2.x, pos2.y, 30);
	}

	float minor_rotation = fmod((*carroIA).rotation*1.0,2.0*Pi);

	float minor_ideal_angle = getAngle(carroPos, target);
	
	if(_auto)
	{
		if (getMinorAngleDiffDirection(minor_rotation, minor_ideal_angle) == 1)
		{
			float anglediff = getMinorAngleDiff(minor_rotation, minor_ideal_angle);
			if (anglediff < Pi/180)
				(*carroIA).direction = Reto;
			else
				(*carroIA).direction = Esquerda;
		}
		else if (getMinorAngleDiffDirection(minor_rotation, minor_ideal_angle) == -1)
		{
			float anglediff = getMinorAngleDiff(minor_rotation, minor_ideal_angle);
			if (anglediff < Pi/180)
				(*carroIA).direction = Reto;
			else
				(*carroIA).direction = Direita;
		}

		if (targetDistance < 30)
		{
			nextPoint++;
			if (_gamescreen == 1)
				saveTargetDistance = cdistance(carroPos, points[nextPoint]);
			else if (_gamescreen == 2)
				saveTargetDistance = cdistance(carroPos, points2[nextPoint]);
			if (nextPoint >= maxPoint)
			{
				nextPoint = 0;
			}
		}
		else
		{
			float ideal_speed = saveTargetDistance/80;
			if (ideal_speed > (*carroIA).maxspeed/6.4 && (*carroIA).direction != Reto)
				ideal_speed = (*carroIA).maxspeed/6.4;
			if (_gamescreen == 1 && (*carroIA).laps >= 3)
				ideal_speed = 0;
			if ((*carroIA).speed < ideal_speed)
				(*carroIA).aceleration = Acelerando;
			else if ((*carroIA).speed > ideal_speed)
				(*carroIA).aceleration = Re;
			else
				(*carroIA).aceleration = Parado;
		}
	}
}

void UpdateCar(float timer, Carro* carro)
{

		float new_pos_x = (*carro).x;
		float new_pos_y = (*carro).y;
		(*carro).oldFrontX = (*carro).x+cos((*carro).rotation)*(*carro).halfwidth;
		(*carro).oldFrontY = (*carro).y+sin((*carro).rotation)*(*carro).halfwidth;
		new_pos_x += cos((*carro).rotation)*(*carro).speed;
		new_pos_y += sin((*carro).rotation)*(*carro).speed;

		int col_status = Colisao_Carro_Fase(new_pos_x+cos((*carro).rotation)*(*carro).halfwidth, new_pos_y+sin((*carro).rotation)*(*carro).halfwidth);
		if ((*carro).speed < 0)
			col_status = Colisao_Carro_Fase(new_pos_x-cos((*carro).rotation)*(*carro).halfwidth, new_pos_y-sin((*carro).rotation)*(*carro).halfwidth);
		
		if(col_status == 1){
			(*carro).x = new_pos_x;
			(*carro).y = new_pos_y;
		}
		else if(col_status == 2){
			(*carro).speed-=0.01*(*carro).speed;

			(*carro).x = new_pos_x;
			(*carro).y = new_pos_y;
		}
		else
		{
				(*carro).speed -= (*carro).speed/10;
		}

		if ((*carro).aceleration == Acelerando)
		{	
			if ((*carro).speed < 0)
				(*carro).speed += 4*timer;
			else
				(*carro).speed += (*carro).engine*timer/15;
		}
		else if ((*carro).aceleration == Parado && (*carro).speed > 0)
		{
			(*carro).speed -= 2*timer;
			if ((*carro).speed < 0)
				(*carro).speed = 0;
		}
		else if ((*carro).aceleration == Parado && (*carro).speed < 0)
		{
			(*carro).speed += 2*timer;
			if ((*carro).speed > 0)
				(*carro).speed = 0;
		}
		else if ((*carro).aceleration == Re)
		{
			if ((*carro).speed > 0)
				(*carro).speed -= 4*timer;
			else
				(*carro).speed -= (*carro).engine*timer/20;
		}
		if ((*carro).direction == Esquerda)
        {
			float newrot = (*carro).rotation;
			if ((*carro).speed > 0)
                newrot += (*carro).handling*timer*(-6.4*pow((*carro).speed,2)/(*carro).maxspeed+(*carro).speed)/(13+pow((*carro).maxspeed/30,3));
			else if ((*carro).speed < 0)
				newrot -= (*carro).handling*timer*(-6.4*pow((*carro).speed+((*carro).maxspeed/6.4),2)/(*carro).maxspeed+(*carro).speed+((*carro).maxspeed/6.4))/(13+pow((*carro).maxspeed/30,3));
			if ((Colisao_Carro_Fase((*carro).x+cos(newrot)*(*carro).halfwidth,(*carro).y+sin(newrot)*(*carro).halfwidth) != 0) && (Colisao_Carro_Fase((*carro).x-cos(newrot)*(*carro).halfwidth,(*carro).y-sin(newrot)*(*carro).halfwidth) != 0))
				(*carro).rotation = newrot;
        }
        else if ((*carro).direction == Direita)
        {
			if ((*carro).speed > 0)
                (*carro).rotation -= (*carro).handling*timer*(-6.4*pow((*carro).speed,2)/(*carro).maxspeed+(*carro).speed)/(13+pow((*carro).maxspeed/30,3));
			else if ((*carro).speed < 0)
				(*carro).rotation += (*carro).handling*timer*(-6.4*pow((*carro).speed+((*carro).maxspeed/6.4),2)/(*carro).maxspeed+(*carro).speed+((*carro).maxspeed/6.4))/(13+pow((*carro).maxspeed/30,3));
        }
		if ((*carro).speed > (*carro).maxspeed/10)
            (*carro).speed = (*carro).maxspeed/10;
		else if ((*carro).speed < -(*carro).maxspeed/15)
			(*carro).speed = -(*carro).maxspeed/15;

		controlLaps(carro);
}

void UpdateAI(float timer, Carro* carro)
{

		float new_pos_x = (*carro).x;
		float new_pos_y = (*carro).y;
		(*carro).oldFrontX = (*carro).x+cos((*carro).rotation)*(*carro).halfwidth;
		(*carro).oldFrontY = (*carro).y+sin((*carro).rotation)*(*carro).halfwidth;
		new_pos_x += cos((*carro).rotation)*(*carro).speed;
		new_pos_y += sin((*carro).rotation)*(*carro).speed;

		//int col_status = Colisao_Carro_Fase(new_pos_x, new_pos_y);
		int col_status = 1;

		if (col_status == 1)
		{
			(*carro).x = new_pos_x;
			(*carro).y = new_pos_y;
		}
		else if (col_status == 2)
		{
			(*carro).speed -= 0.01*(*carro).speed;

			(*carro).x = new_pos_x;
			(*carro).y = new_pos_y;
		}
		else
		{
		//	(*carro).speed-=(*carro).speed;
		}

		if ((*carro).aceleration == Acelerando)
		{	
			if ((*carro).speed < 0)
				(*carro).speed += 4*timer;
			else
				(*carro).speed += (*carro).engine*timer/15;
		}
		else if ((*carro).aceleration == Parado && (*carro).speed > 0)
		{
			(*carro).speed -= 2*timer;
			if ((*carro).speed < 0)
				(*carro).speed = 0;
		}
		else if ((*carro).aceleration == Parado && (*carro).speed < 0)
		{
			(*carro).speed += 2*timer;
			if ((*carro).speed > 0)
				(*carro).speed = 0;
		}
		else if ((*carro).aceleration == Re)
		{
			if ((*carro).speed > 0)
				(*carro).speed -= 4*timer;
			else
				(*carro).speed -= (*carro).engine*timer/20;
		}
		if ((*carro).direction == Esquerda)
        {
			if ((*carro).speed > 0)
                (*carro).rotation += (*carro).handling*timer*(-6.4*pow((*carro).speed,2)/(*carro).maxspeed+(*carro).speed)/(13+pow((*carro).maxspeed/30,3));
			else if ((*carro).speed < 0)
				(*carro).rotation -= (*carro).handling*timer*(-6.4*pow((*carro).speed+((*carro).maxspeed/6.4),2)/(*carro).maxspeed+(*carro).speed+((*carro).maxspeed/6.4))/(13+pow((*carro).maxspeed/30,3));
        }
        else if ((*carro).direction == Direita)
        {
			if ((*carro).speed > 0)
                (*carro).rotation -= (*carro).handling*timer*(-6.4*pow((*carro).speed,2)/(*carro).maxspeed+(*carro).speed)/(13+pow((*carro).maxspeed/30,3));
			else if ((*carro).speed < 0)
				(*carro).rotation += (*carro).handling*timer*(-6.4*pow((*carro).speed+((*carro).maxspeed/6.4),2)/(*carro).maxspeed+(*carro).speed+((*carro).maxspeed/6.4))/(13+pow((*carro).maxspeed/30,3));
        }
		if ((*carro).speed > (*carro).maxspeed/10)
            (*carro).speed = (*carro).maxspeed/10;
		else if ((*carro).speed < -(*carro).maxspeed/15)
			(*carro).speed = -(*carro).maxspeed/15;

		controlLaps(carro);
}

////////////////////////Draw:
void Draw()
{
	float xscale = 1024 / 1432.0;
	float yscale = 768 / 1075.0;


	if (_gamescreen == -2)
	{
	/*<index>*/
		graphics.DrawImage2D(0, 0, 1024,768, png_fundo);
		graphics.DrawText2D(15,570,"Tempo do Jogador em cada pista:");
		graphics.DrawText2D(15,550,"Pista 1:");
		graphics.DrawText2D(15,530,"Primeira volta: %.2f segundos", player.lapTime[0][0]);
		graphics.DrawText2D(15,510,"Segunda volta: %.2f segundos", player.lapTime[0][1]);
		graphics.DrawText2D(15,490,"Terceira volta: %.2f segundos", player.lapTime[0][2]);
		graphics.DrawText2D(15,470,"Pista 2:");
		graphics.DrawText2D(15,450,"Primeira volta: %.2f segundos", player.lapTime[1][0]);
		graphics.DrawText2D(15,430,"Segunda volta: %.2f segundos", player.lapTime[1][1]);
		graphics.DrawText2D(15,410,"Terceira volta: %.2f segundos", player.lapTime[1][2]);
	/*</index>*/
	}
	else if (_gamescreen == 0)
	{
	/*<index>*/
		graphics.DrawImage2D(0, 0, 1024,768, png_fundo);
		graphics.DrawImage2D(70, 470, 224, 80, png_botao_jogar);
		graphics.DrawImage2D(70, 380, 224, 80, png_botao_placar);
	/*</index>*/
	}
	else if (_gamescreen == 1)
	{
		graphics.DrawImage2D(0, 0, 1024, 768, -835+player.x, -519-player.y, 1433.6, 1075.2, png_pista1);
		//graphics.DrawImage2D(0, 0, 1024, 768, -838+player.x, -595-player.y, 1433.6, 1075.2, png_pista1);
		//graphics.DrawImage2D(0, 0, 1024, 768, -860+player.x, -519-player.y, 1433.6, 1075.2, png_pista1);
		graphics.SetColor(0,200,200);
		_wrongdir = getWrongDir1(player.x,player.y,player.rotation);
		if (_wrongdir)
			graphics.DrawText2D(450,690,"Sentido Inverso!");
	}
	else if (_gamescreen == 2)
	{
		graphics.DrawImage2D(0, 0, 1024, 768, -422+player.x, -274-player.y, 731.53, 568.57, png_pista2);
	}
	else if (_gamescreen == 3)
	{
		graphics.DrawImage2D(0, 0, 1024, 768, -425+player.x, -273-player.y, 731.53, 568.57, png_pista3);
	}

	if (_gamescreen != 0 && _gamescreen != -1 && _gamescreen != -2)
	{
		graphics.SetColor(200,40,40);

		Position inimigo1_pos = PosInScreen(inimigo1.x-131, inimigo1.y-141);//131
		graphics.RotateBegin(-90+inimigo1.rotation*180/Pi);
		graphics.DrawImage2D(inimigo1_pos.x, inimigo1_pos.y, 200, 200, png_inimigo1);
		graphics.RotateEnd();

		//graphics.FillCircle2D(inimigo1_pos.x+131*_xscale, inimigo1_pos.y+131*_yscale, 5, 10);

		graphics.RotateBegin(-90+player.rotation*180/Pi);
		graphics.DrawImage2D(495, 300, 200, 200, png_carro1);
		graphics.RotateEnd();

		//graphics.FillCircle2D(594, 400, 5, 10);

		graphics.DrawText2D(15,710,"Velocidade: %.0fkm/h",abs(player.speed*35/2));
		//graphics.DrawText2D(15,690,"Velocidade inimigo: %.0fkm/h",abs(inimigo1.speed*35/2));
		graphics.DrawText2D(15,660,"seu x: %f", player.x);
		graphics.DrawText2D(15,640,"seu y: %f", player.y);
		//graphics.DrawText2D(15,620,"tecla: %d", teste);
		//graphics.DrawText2D(15,620,"inimigo x: %f", inimigo1.x);
		//graphics.DrawText2D(15,600,"inimigo y: %f", inimigo1.y);
		if (player.laps >= 0)
			graphics.DrawText2D(15,690,"Laps: %d", player.laps);
		else
			graphics.DrawText2D(15,690,"Laps: 0");

		int secondconvert = (int) _gtimer;
		int seconds = fmod(secondconvert*1.0,60);
		int minutes = (int) _gtimer/60;
		if (seconds >= 10)
			graphics.DrawText2D(15,670,"Tempo: 0%d:%d", minutes, seconds);
		else
			graphics.DrawText2D(15,670,"Tempo: 0%d:0%d", minutes, seconds);
		//graphics.DrawText2D(15,560,"laps inimigo: %d", inimigo1.laps);
	}
	if (_msg == 1 || _msg == 2)
	{
		if (_msg == 1)
		{
			graphics.DrawImage2D(0, 0, 1024, 768, png_paper1);
		}
		else if (_msg == 2)
		{
			graphics.DrawImage2D(0, 0, 1024, 768, png_instrucoes);
		}
		graphics.DrawImage2D(png_botao_continuar);
	}
}


//////////////////////////Sound:

void Sound()
{
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
		if (musica_1.IsPlaying())
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
}