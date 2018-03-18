enum musicstate {
    Tocar,
    Trocar,
    Parar
};

enum acelerationstate {
    Re = -1,
    Parado,
    Acelerando
};

enum directionstate {
    Reto,
    Esquerda,
    Direita
};

typedef struct stCars {
    int aceleration;
    int direction;
    float speed;
    float x;
    float y;
	float oldFrontX;
    float oldFrontY;
    float rotation;
    float maxspeed;
    int engine;
    int handling;
	int laps;
	float halfwidth;
	float lapTime[3][3];
} Carro;

typedef struct stMusica {
    int state;
} Musica;

typedef struct stPressedkeys {
    bool left;
    bool right;
    bool down;
    bool up;
} Keypress;

Carro player;
Carro inimigo1;

Musica musica;
Keypress p;
Graphics graphics;
Image png_fundo, png_loading, png_som, png_musica, png_botao_jogar, png_botao_placar, png_pista1, png_pista2, png_pista3, png_player, png_carro1, png_carro2, png_carro3, png_inimigo1, png_sinal1, png_sinal2, png_sinal3, png_sinal4, png_instrucoes, png_paper1, png_botao_continuar;
Audio musica_1, som_1;
vector<vector<char>> map1_col;
vector<vector<char>> map2_col;
int _gamescreen = -1;
bool _race = false, _wrongdir = false;
float _xscale = 1024 / 1432.0;
float _yscale = 768 / 1075.0;

float _saveplayerscore[3][3];
int _save = 0;
int _msg = 0;

int teste = 0;

int countdown = 10;
int _racestart = 0;
int _signkeep = 0;
float _gtimer = 0;

typedef struct {
	 float x;
	 float y;
} Position;

//////// IA //////////
bool _debug_mode = false;
bool _auto = true;
Position points[28];
Position points2[74];
int nextPoint = 0;
int maxPoint = 0;
/////////////////////

void FirstScore()
{
	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 3; b++)
			_saveplayerscore[a][b] = 0;
}

void ResetVariables()
{
/*<Definindo as variáveis>*/
    p.down = false;
    p.up = false;
    p.left = false;
    p.right = false;

    player.x = 3735;
    //player.y = 1462.4;
	player.y = 1475;
    player.speed = 0;
    player.direction = Reto;
    player.aceleration = Parado;
    player.rotation = Pi/2;
    player.engine = 7;
    player.handling = 20;
    player.maxspeed = 40;
	player.laps = -1;
	player.halfwidth = 80;
	if (_save == 0)
	{
	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 3; b++)
			player.lapTime[a][b] = 0;
	}

	inimigo1.x = points[0].x;
	//inimigo1.y = 1462.4;
	inimigo1.y = 1475;
	inimigo1.speed = 0;
	inimigo1.direction = Reto;
	inimigo1.aceleration = Parado;
	inimigo1.rotation = Pi/2;
	inimigo1.engine = 9;
	inimigo1.handling = 80;
	inimigo1.maxspeed = 40;
	inimigo1.laps = -1;
	inimigo1.halfwidth = 80;

	nextPoint = 0;

	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 3; b++)
			inimigo1.lapTime[a][b] = 0;
/*</Definindo as variáveis>*/
}