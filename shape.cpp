#include "shape.h"

/////////////////////////////////////////////////////////////

Shape::~Shape()
{
}

/////////////////////////////////////////////////////////////

Rect::Rect (int _x, int _y)
{
    x = _x;
    y = _y;
    w = 50 + rand() % 50;
    h = 50 + rand() % 50;
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
}

void Rect::Draw(HDC hdc)
{
    HBRUSH hBrush = CreateSolidBrush (RGB (r, g, b)) ;
    SelectObject (hdc, hBrush) ;
    Rectangle (hdc, x-w, y-h, x+w, y+h) ;
    DeleteObject (hBrush) ;
}

/////////////////////////////////////////////////////////////

Square::Square (int _x, int _y)
{
    x = _x;
    y = _y;
    w = 50 + rand() % 50;
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
}

void Square::Draw(HDC hdc)
{
    HBRUSH hBrush = CreateSolidBrush (RGB (r, g, b)) ;
    SelectObject (hdc, hBrush) ;
    Rectangle (hdc, x-w, y-w, x+w, y+w) ;
    DeleteObject (hBrush) ;
}

/////////////////////////////////////////////////////////////

Circle::Circle (int _x, int _y)
{
    x = _x;
    y = _y;
    w = 50 + rand() % 50;
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
}

void Circle::Draw(HDC hdc)
{
    HBRUSH hBrush = CreateSolidBrush (RGB (r, g, b)) ;
    SelectObject (hdc, hBrush) ;
    Ellipse (hdc, x-w, y-w, x+w, y+w) ;
    DeleteObject (hBrush) ;
}

/////////////////////////////////////////////////////////////

ShapeGame::ShapeGame()
{
    numShapes = 0;
}

void ShapeGame::AddDrawShape(HDC hdc, int x, int y)
{
    int type = rand()%3;
    if(type==0)
        shapes[numShapes] = new Rect(x, y);
    else if(type==1)
        shapes[numShapes] = new Square(x, y);
    else if(type==2)
        shapes[numShapes] = new Circle(x, y);
    shapes[numShapes]->Draw(hdc);
    numShapes++;
}

void ShapeGame::DrawShapes(HDC hdc)
{
    int i;
    for(i=0; i<numShapes; i++)
        shapes[i]->Draw(hdc);
}

void ShapeGame::DestroyShapes()
{
    int i;
    for(i=0; i<numShapes; i++)
        delete shapes[i];
    numShapes = 0;
}

ShapeGame::~ShapeGame()
{
    DestroyShapes();
}
bool Rect ::IsInside(int x, int y)
{
    if (this->x+w <x || this->y+h<y || this->x-w>x || this->y-h>y)
    {
        return false;
    }
    else
        return true ;

}
bool Square :: IsInside (int x, int y)
{
    if (this->x+w <x  || this->x-w>x || this->y-w>y || this->y+w<y)
    {
        return false;
    }
    else
        return true ;

}
bool Circle :: IsInside (int x, int y)
{
    if ((this->x-x) * (this->x-x) + (this->y-y) * (this->y-y)<=w*w)
    {
        return  true ;
    }
    else
        return false;

}
void Rect :: MoveTo(int x, int y)
{
    this->x=x;
    this->y=y;

}
void Square :: MoveTo(int x, int y)
{
    this->x=x;
    this->y=y;

}
void Circle:: MoveTo(int x, int y)
{
    this->x=x;
    this->y=y;

}


void ShapeGame :: StartMove(int x, int y)
{

    stx=x;
    sty=y;
}

void ShapeGame :: EndMove(int x, int y)
{
    for(int i=numShapes-1; i>=0; i--)
    {
        if(shapes[i]->IsInside(stx,sty))
        {
            if (i!=numShapes-1)
            {
//numShapes++;

                auto x=shapes[i];
                for(int j=i; j<numShapes-1; j++)
                {
                    shapes[j]=shapes[j+1];
                }


                shapes[numShapes-1]=x;
                shapes[numShapes-1]->MoveTo(stx,sty);

                break;
            }
            else
            {
                shapes[i]->MoveTo(stx,sty);
                break;
            }
        }

    }
}
double Rect ::Area()
{
    return 4*(double)h*(double)w;
}
double Square ::Area()
{
    return 4*(double)x*(double)x;
}
double Circle ::Area()
{
    return 22/7*(double)w*(double)w;
}
double ShapeGame :: GetArea()
{


   double x=shapes[numShapes-1]->Area();
   return x;


}
