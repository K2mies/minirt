#include "minirt.h"

void	print_3d_data_array(char	***arr)
{
	int	i = -1;

	while (arr[++i])
	{
		int j = -1;
		while (arr[i][++j])
			printf("Line %d Element %d - %s\n", i + 1, j + 1, arr[i][j]);
	}
}

void	print_stored_data(t_minirt *rt)
{
	int	i = -1;
	printf("\n///////// DATA STRUCT /////////\n");
	printf("///// Ambient /////\n");
	printf("Ratio: %f\n", rt->ambient.ratio);
	printf("RGB: %f,%f,%f\n", rt->ambient.color.r, rt->ambient.color.g, rt->ambient.color.b);
	printf("\n");
	printf("///// Camera /////\n");
	printf("Origin: %f,%f,%f\n", rt->camera.origin.x, rt->camera.origin.y, rt->camera.origin.z);
	printf("Vector: %f,%f,%f\n", rt->camera.vector.x, rt->camera.vector.y, rt->camera.vector.z);
	printf("FOV: %d\n", rt->camera.fov);
	printf("\n");
	printf("///// Light /////\n");
	printf("Origin: %f,%f,%f\n", rt->light.origin.x, rt->light.origin.y, rt->light.origin.z);
	printf("Brightness: %f\n", rt->light.brightness);
	printf("RGB: %f,%f,%f\n", rt->light.color.r, rt->light.color.g, rt->light.color.b);
	printf("\n");
	printf("///// Objects /////\n");
	while (rt->object[++i])
	{
		if (rt->object[i]->type == SPHERE)
		{
			printf("Type: %d (0 = Sphere, 1 = Plane, 2 = Cylinder)\n", rt->object[i]->type);
			printf("Origin: %f,%f,%f\n", rt->object[i]->origin.x, rt->object[i]->origin.y, rt->object[i]->origin.z);
			printf("Diameter: %f\n", rt->object[i]->diameter);
			printf("RGB: %f,%f,%f\n", rt->object[i]->color.r, rt->object[i]->color.g, rt->object[i]->color.b);
			printf("\n");
		}
		else if (rt->object[i]->type == PLANE)
		{
			printf("Type: %d (0 = Sphere, 1 = Plane, 2 = Cylinder)\n", rt->object[i]->type);
			printf("Origin: %f,%f,%f\n", rt->object[i]->origin.x, rt->object[i]->origin.y, rt->object[i]->origin.z);
			printf("Vector: %f,%f,%f\n", rt->object[i]->vector.x, rt->object[i]->vector.y, rt->object[i]->vector.z);
			printf("RGB: %f,%f,%f\n", rt->object[i]->color.r, rt->object[i]->color.g, rt->object[i]->color.b);
			printf("\n");
		}
		else if (rt->object[i]->type == CYLINDER)
		{
			printf("Type: %d (0 = Sphere, 1 = Plane, 2 = Cylinder)\n", rt->object[i]->type);
			printf("Origin: %f,%f,%f\n", rt->object[i]->origin.x, rt->object[i]->origin.y, rt->object[i]->origin.z);
			printf("Vector: %f,%f,%f\n", rt->object[i]->vector.x, rt->object[i]->vector.y, rt->object[i]->vector.z);
			printf("Diameter: %f\n", rt->object[i]->diameter);
			printf("Height: %f\n", rt->object[i]->height);
			printf("RGB: %f,%f,%f\n", rt->object[i]->color.r, rt->object[i]->color.g, rt->object[i]->color.b);
			printf("\n");
		}
	}
}