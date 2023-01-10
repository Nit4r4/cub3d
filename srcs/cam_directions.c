#include "../include/cub3d.h"

void	move_left_camera(t_cub *cub, float new_x, float new_y)
{
	cub->pos.a -= 1;
	if (cub->pos.a < degree_to_radian(0))
		cub->pos.a = degree_to_radian(360);
	float	new_dirx;

	new_x = cub->play.distx;
	new_y = cub->play.disty;
	new_dirx = cub->play.dirx;
	// cub->play.distx = cub->play.distx * cos(degree_to_radian(1)) - cub->play.disty * sin(RSP);
	// cub->play.disty = new_x * sin(RSP) + cub->play.disty * cos(RSP);
	// cub->play.dirx = cub->play.dirx * cos(RSP) - cub->play.diry * sin(RSP);
	// cub->play.diry = new_dirx * sin(RSP) + cub->play.diry * cos(RSP);
}
void	move_right_camera(t_cub *cub, float new_x, float new_y)
{
	float	new_dirx;
	cub->pos.a += 1;
	if (cub->pos.a > 360)
		cub->pos.a = 0;

	new_x = cub->play.distx;
	new_y = cub->play.disty;
	new_dirx = cub->play.dirx;
	// cub->play.distx = cub->play.distx * cos(-RSP) - cub->play.disty * sin(-RSP);
	// cub->play.disty = new_x * sin(-RSP) + cub->play.disty * cos(-RSP);
	// cub->play.dirx = cub->play.dirx * cos(-RSP) - cub->play.diry * sin(-RSP);
	// cub->play.diry = new_dirx * sin(-RSP) + cub->play.diry * cos(-RSP);
}

//probleme de calculs a ressoudre ici et a integrer das les directons  PASSER LES FONCTIONS EN INT ET RETOURNER DES 0 OU DES 1 !
