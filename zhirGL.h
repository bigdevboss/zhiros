Point vertices_cube[] = {
        {200, 450},
        {600, 450},
        {600, 300},
        {400, 200},
        {200, 300},
};

void draw_figure() {
        int size = sizeof(vertices_cube)/sizeof(vertices_cube[0]);   

        vec2 centered = center_figure(vertices_cube, size);

        fill_polygon(vertices_cube, size,  0xFFFFFF);
}

//исполняемая функция в kernel.c
void draw_some() {
	draw_figure();
}