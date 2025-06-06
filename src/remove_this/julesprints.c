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
	while (++i < rt->n_objs)
	{
		if (rt->objs[i].type == SPHERE)
		{
			printf("Type: %d (0 = Sphere, 1 = Plane, 2 = Cylinder)\n", rt->objs[i].type);
			printf("Origin: %f,%f,%f\n", rt->objs[i].origin.x, rt->objs[i].origin.y, rt->objs[i].origin.z);
			printf("Diameter: %f\n", rt->objs[i].diameter);
			printf("Radius: %f\n", rt->objs[i].radius);
			printf("RGB: %f,%f,%f\n", rt->objs[i].color.r, rt->objs[i].color.g, rt->objs[i].color.b);
			printf("- Material -\nRGB: %f,%f,%f | Ambient: %f | Diffuse: %f | Specular: %f | Shininess: %f\n", rt->objs[i].material.color.r, rt->objs[i].material.color.g, rt->objs[i].material.color.b, rt->objs[i].material.ambient, rt->objs[i].material.diffuse, rt->objs[i].material.specular, rt->objs[i].material.shininess);
			printf("- Matrix4 -\n");
			int a = -1;
			while (++a < 4)
			{
				int b = -1;
				while (++b < 4)
				{
					printf("%f", rt->objs[i].transform.m[a][b]);
					if (b != 3)
						printf(",");
					else
						printf("\n");
				}
			}
			printf("\n");
		}
		else if (rt->objs[i].type == PLANE)
		{
			printf("Type: %d (0 = Sphere, 1 = Plane, 2 = Cylinder)\n", rt->objs[i].type);
			printf("Origin: %f,%f,%f\n", rt->objs[i].origin.x, rt->objs[i].origin.y, rt->objs[i].origin.z);
			printf("Vector: %f,%f,%f\n", rt->objs[i].vector.x, rt->objs[i].vector.y, rt->objs[i].vector.z);
			printf("RGB: %f,%f,%f\n", rt->objs[i].color.r, rt->objs[i].color.g, rt->objs[i].color.b);
			printf("- Material -\nRGB: %f,%f,%f | Ambient: %f | Diffuse: %f | Specular: %f | Shininess: %f\n", rt->objs[i].material.color.r, rt->objs[i].material.color.g, rt->objs[i].material.color.b, rt->objs[i].material.ambient, rt->objs[i].material.diffuse, rt->objs[i].material.specular, rt->objs[i].material.shininess);
			printf("- Matrix4 -\n");
			int a = -1;
			while (++a < 4)
			{
				int b = -1;
				while (++b < 4)
				{
					printf("%f", rt->objs[i].transform.m[a][b]);
					if (b != 3)
						printf(",");
					else
						printf("\n");
				}
			}
			printf("\n");
		}
		else if (rt->objs[i].type == CYLINDER)
		{
			printf("Type: %d (0 = Sphere, 1 = Plane, 2 = Cylinder)\n", rt->objs[i].type);
			printf("Origin: %f,%f,%f\n", rt->objs[i].origin.x, rt->objs[i].origin.y, rt->objs[i].origin.z);
			printf("Vector: %f,%f,%f\n", rt->objs[i].vector.x, rt->objs[i].vector.y, rt->objs[i].vector.z);
			printf("Diameter: %f\n", rt->objs[i].diameter);
			printf("Height: %f\n", rt->objs[i].height);
			printf("RGB: %f,%f,%f\n", rt->objs[i].color.r, rt->objs[i].color.g, rt->objs[i].color.b);
			printf("- Material -\nRGB: %f,%f,%f | Ambient: %f | Diffuse: %f | Specular: %f | Shininess: %f\n", rt->objs[i].material.color.r, rt->objs[i].material.color.g, rt->objs[i].material.color.b, rt->objs[i].material.ambient, rt->objs[i].material.diffuse, rt->objs[i].material.specular, rt->objs[i].material.shininess);
			printf("- Matrix4 -\n");
			int a = -1;
			while (++a < 4)
			{
				int b = -1;
				while (++b < 4)
				{
					printf("%f", rt->objs[i].transform.m[a][b]);
					if (b != 3)
						printf(",");
					else
						printf("\n");
				}
			}
			printf("\n");
		}
	}
}
