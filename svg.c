
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include"svg.h"

// --------------------------------------------------------
// STATIC FUNCTION appendstringtosvg
// --------------------------------------------------------
static void appendstringtosvg(svg* psvg, char* text)
{
    int l = strlen(psvg->svg) + strlen(text) + 1;

    char* p = realloc(psvg->svg, l);

    if(p)
    {
        psvg->svg = p;
    }

    strcat(psvg->svg, text);
}

// --------------------------------------------------------
// STATIC FUNCTION appendnumbertosvg
// --------------------------------------------------------
static void appendnumbertosvg(svg* psvg, int n)
{
    char sn[16];

    sprintf(sn, "%d", n);

    appendstringtosvg(psvg, sn);
}

// --------------------------------------------------------
// FUNCTION svg_create
// --------------------------------------------------------
svg* svg_create(int width, int height)
{
    svg* psvg = malloc(sizeof(svg));

    if(psvg != NULL)
    {
        *psvg = (svg){.svg = NULL, .width = width, .height = height, .finalized = false};

        psvg->svg = malloc(1);

        sprintf(psvg->svg, "%s", "\0");

        appendstringtosvg(psvg, "<svg width='");
        appendnumbertosvg(psvg, width);
        appendstringtosvg(psvg, "px' height='");
        appendnumbertosvg(psvg, height);
        appendstringtosvg(psvg, "px' xmlns='http://www.w3.org/2000/svg' version='1.1' xmlns:xlink='http://www.w3.org/1999/xlink'>\n");

        return psvg;
    }
    else
    {
        return NULL;
    }
}

// --------------------------------------------------------
// FUNCTION svg_finalize
// --------------------------------------------------------
void svg_finalize(svg* psvg)
{
    appendstringtosvg(psvg, "</svg>");

    psvg->finalized = true;
}

// --------------------------------------------------------
// FUNCTION svg_print
// --------------------------------------------------------
void svg_print(svg* psvg)
{
    printf("%s\n", psvg->svg);
}

// --------------------------------------------------------
// FUNCTION svg_save
// --------------------------------------------------------
void svg_save(svg* psvg, char* filepath)
{
    if(!psvg->finalized)
    {
        svg_finalize(psvg);
    }

    FILE* fp;

	fp = fopen(filepath, "w");

	if(fp != NULL)
	{
		fwrite(psvg->svg, 1, strlen(psvg->svg), fp);

		fclose(fp);
	}
}

//----------------------------------------------------------------
// FUNCTION svg_free
//----------------------------------------------------------------
void svg_free(svg* psvg)
{
    free(psvg->svg);

    free(psvg);
}

//----------------------------------------------------------------
// FUNCTION svg_circle
//----------------------------------------------------------------
void svg_circle(svg* psvg, char* stroke, int strokewidth, char* fill, int r, int cx, int cy)
{
    appendstringtosvg(psvg, "    <circle stroke='");
    appendstringtosvg(psvg, stroke);
    appendstringtosvg(psvg, "' stroke-width='");
    appendnumbertosvg(psvg, strokewidth);
    appendstringtosvg(psvg, "px' fill='");
    appendstringtosvg(psvg, fill);
    appendstringtosvg(psvg, "' r='");
    appendnumbertosvg(psvg, r);
    appendstringtosvg(psvg, "' cy='");
    appendnumbertosvg(psvg, cy);
    appendstringtosvg(psvg, "' cx='");
    appendnumbertosvg(psvg, cx);
    appendstringtosvg(psvg, "' />\n");
}

//----------------------------------------------------------------
// FUNCTION svg_line
//----------------------------------------------------------------
void svg_line(svg* psvg, char* stroke, int strokewidth, int x1, int y1, int x2, int y2)
{
    appendstringtosvg(psvg, "    <line stroke='");
    appendstringtosvg(psvg, stroke);
    appendstringtosvg(psvg, "' stroke-width='");
    appendnumbertosvg(psvg, strokewidth);
    appendstringtosvg(psvg, "px' y2='");
    appendnumbertosvg(psvg, y2);
    appendstringtosvg(psvg, "' x2='");
    appendnumbertosvg(psvg, x2);
    appendstringtosvg(psvg, "' y1='");
    appendnumbertosvg(psvg, y1);
    appendstringtosvg(psvg, "' x1='");
    appendnumbertosvg(psvg, x1);
    appendstringtosvg(psvg, "' />\n");
}

//----------------------------------------------------------------
// FUNCTION svg_rectangle
//----------------------------------------------------------------
void svg_rectangle(svg* psvg, int width, int height, int x, int y, char* fill, char* stroke, int strokewidth, int radiusx, int radiusy)
{
    appendstringtosvg(psvg, "    <rect fill='");
    appendstringtosvg(psvg, fill);
    appendstringtosvg(psvg, "' stroke='");
    appendstringtosvg(psvg, stroke);
    appendstringtosvg(psvg, "' stroke-width='");
    appendnumbertosvg(psvg, strokewidth);
    appendstringtosvg(psvg, "px' width='");
    appendnumbertosvg(psvg, width);
    appendstringtosvg(psvg, "' height='");
    appendnumbertosvg(psvg, height);
    appendstringtosvg(psvg, "' y='");
    appendnumbertosvg(psvg, y);
    appendstringtosvg(psvg, "' x='");
    appendnumbertosvg(psvg, x);
    appendstringtosvg(psvg, "' ry='");
    appendnumbertosvg(psvg, radiusy);
    appendstringtosvg(psvg, "' rx='");
    appendnumbertosvg(psvg, radiusx);
    appendstringtosvg(psvg, "' />\n");
}

// --------------------------------------------------------
// FUNCTION svg_fill
// --------------------------------------------------------
void svg_fill(svg* psvg, char* Fill)
{
    svg_rectangle(psvg, psvg->width, psvg->height, 0, 0, Fill, Fill, 0, 0, 0);
}

//----------------------------------------------------------------
// FUNCTION svg_text
//----------------------------------------------------------------
void svg_text(svg* psvg, int x, int y, char* fontfamily, int fontsize, char* fill, char* stroke, char* text)
{
    appendstringtosvg(psvg, "    <text x='");
    appendnumbertosvg(psvg, x);
    appendstringtosvg(psvg, "' y = '");
    appendnumbertosvg(psvg, y);
    appendstringtosvg(psvg, "' font-family='");
    appendstringtosvg(psvg, fontfamily);
    appendstringtosvg(psvg, "' stroke='");
    appendstringtosvg(psvg, stroke);
    appendstringtosvg(psvg, "' fill='");
    appendstringtosvg(psvg, fill);
    appendstringtosvg(psvg, "' font-size='");
    appendnumbertosvg(psvg, fontsize);
    appendstringtosvg(psvg, "px'>");
    appendstringtosvg(psvg, text);
    appendstringtosvg(psvg, "</text>\n");
}

//----------------------------------------------------------------
// FUNCTION svg_ellipse
//----------------------------------------------------------------
void svg_ellipse(svg* psvg, int cx, int cy, int rx, int ry, char* fill, char* stroke, int strokewidth)
{
    appendstringtosvg(psvg, "    <ellipse cx='");
    appendnumbertosvg(psvg, cx);
    appendstringtosvg(psvg, "' cy='");
    appendnumbertosvg(psvg, cy);
    appendstringtosvg(psvg, "' rx='");
    appendnumbertosvg(psvg, rx);
    appendstringtosvg(psvg, "' ry='");
    appendnumbertosvg(psvg, ry);
    appendstringtosvg(psvg, "' fill='");
    appendstringtosvg(psvg, fill);
    appendstringtosvg(psvg, "' stroke='");
    appendstringtosvg(psvg, stroke);
    appendstringtosvg(psvg, "' stroke-width='");
    appendnumbertosvg(psvg, strokewidth);
    appendstringtosvg(psvg, "' />\n");
}
