
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

#include"svg.h"

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
void drawrectangles(void);
void drawallshapes(void);
void iwanttobelieve(void);
void mondrian(void);
void stochasticpi(void);

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main(void)
{
    puts("-----------------");
    puts("| codedrome.com |");
    puts("| SVG Library   |");
    puts("-----------------\n");

    //drawrectangles();

    //drawallshapes();

    //iwanttobelieve();

    //mondrian();

    return EXIT_SUCCESS;
}

// --------------------------------------------------------
// FUNCTION drawrectangles
// --------------------------------------------------------
void drawrectangles(void)
{
    svg* psvg;
    psvg = svg_create(512, 512);

    if(psvg == NULL)
    {
        puts("psvg is NULL");
    }
    else
    {
        svg_rectangle(psvg, 512, 512, 0, 0, "#C0C0FF", "black", 1, 0, 0);

        svg_rectangle(psvg, 384, 384, 64, 64, "#00FF00", "#000000", 4, 0, 0);
        svg_rectangle(psvg, 320, 320, 96, 96, "#FFFF00", "#000000", 2, 8, 8);
        svg_rectangle(psvg, 256, 256, 128, 128, "#00FFFF", "#000000", 2, 8, 8);
        svg_rectangle(psvg, 192, 192, 160, 160, "#FF80FF", "#000000", 2, 8, 8);

        svg_finalize(psvg);
        svg_save(psvg, "rectangles.svg");
        svg_free(psvg);
    }
}

// --------------------------------------------------------
// FUNCTION drawallshapes
// --------------------------------------------------------
void drawallshapes(void)
{
    svg* psvg;
    psvg = svg_create(192, 320);

    if(psvg == NULL)
    {
        puts("psvg is NULL");
    }
    else
    {
        svg_fill(psvg, "#DADAFF");

        svg_text(psvg, 32, 32, "sans-serif", 16, "#000000", "#000000", "drawallshapes");
        svg_circle(psvg, "#000080", 4, "#0000FF", 32, 64, 96);
        svg_ellipse(psvg, 64, 160, 32, 16, "#FF0000", "#800000", 4);

        svg_line(psvg, "#000000", 2, 32, 192, 160, 192);

        svg_rectangle(psvg, 64, 64, 32, 224, "#00FF00", "#008000", 4, 4, 4);

        svg_finalize(psvg);
        svg_print(psvg);
        svg_save(psvg, "allshapes.svg");
        svg_free(psvg);
    }
}

// --------------------------------------------------------
// FUNCTION iwanttobelieve
// --------------------------------------------------------
void iwanttobelieve(void)
{
    svg* psvg;
    psvg = svg_create(512, 768);

    if(psvg == NULL)
    {
        puts("psvg is NULL");
    }
    else
    {
        svg_fill(psvg, "#000010");

        srand(time(NULL));
        int x, y;
        for(int s = 0; s <= 512; s++)
        {
            x = (rand() % 512);
            y = (rand() % 768);

            svg_rectangle(psvg, 1, 1, x, y, "white", "white", 0, 0, 0);
        }

        svg_text(psvg, 96, 712, "sans-serif", 32, "#FFFFFF", "#FFFFFF", "I WANT TO BELIEVE");

        svg_circle(psvg, "silver", 1, "rgba(0,0,0,0)", 28, 256, 384);

        svg_ellipse(psvg, 256, 374, 8, 14, "#808080", "#808080", 0);
        svg_ellipse(psvg, 252, 372, 3, 2, "#000000", "#000000", 0);
        svg_ellipse(psvg, 260, 372, 3, 2, "#000000", "#000000", 0);
        svg_rectangle(psvg, 1, 1, 251, 371, "white", "white", 0, 0, 0);
        svg_rectangle(psvg, 1, 1, 259, 371, "white", "white", 0, 0, 0);
        svg_line(psvg, "black", 2, 254, 378, 258, 378);

        svg_line(psvg, "silver", 2, 234, 416, 226, 432);
        svg_line(psvg, "silver", 2, 278, 416, 286, 432);
        svg_ellipse(psvg, 256, 400, 64, 16, "silver", "silver", 4);

        svg_finalize(psvg);
        svg_save(psvg, "iwanttobelieve.svg");
        svg_free(psvg);
    }
}

// --------------------------------------------------------
// FUNCTION mondrian
// --------------------------------------------------------
void mondrian(void)
{
    svg* psvg;
    psvg = svg_create(512, 512);

    if(psvg == NULL)
    {
        puts("psvg is NULL");
    }
    else
    {
        svg_fill(psvg, "white");

        svg_rectangle(psvg, 512, 512, 0, 0, "white", "black", 1, 0, 0);

        svg_rectangle(psvg, 256, 256, 64, 64, "red", "red", 0, 0, 0);
        svg_rectangle(psvg, 128, 128, 64, 320, "black", "black", 0, 0, 0);
        svg_rectangle(psvg, 64, 128, 0, 384, "orange", "orange", 0, 0, 0);
        svg_rectangle(psvg, 128, 192, 320, 0, "orange", "orange", 0, 0, 0);
        svg_rectangle(psvg, 128, 64, 320, 384, "navy", "navy", 0, 0, 0);
        svg_rectangle(psvg, 64, 128, 448, 384, "red", "red", 0, 0, 0);

        svg_line(psvg, "black", 8, 0, 64, 448, 64);
        svg_line(psvg, "black", 8, 64, 64, 64, 512);
        svg_line(psvg, "black", 8, 0, 192, 64, 192);
        svg_line(psvg, "black", 8, 0, 384, 512, 384);
        svg_line(psvg, "black", 8, 128, 0, 128, 64);
        svg_line(psvg, "black", 8, 320, 0, 320, 448);
        svg_line(psvg, "black", 8, 64, 320, 448, 320);
        svg_line(psvg, "black", 8, 320, 192, 448, 192);
        svg_line(psvg, "black", 8, 64, 448, 448, 448);
        svg_line(psvg, "black", 8, 448, 0, 448, 512);
        svg_line(psvg, "black", 8, 192, 320, 192, 512);
        svg_line(psvg, "black", 8, 384, 192, 384, 320);

        svg_finalize(psvg);
        svg_save(psvg, "mondrian.svg");
        svg_free(psvg);
    }
}
