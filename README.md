We were asked to improve the code to make the shapes move from point to other if that point was inside the body of the shape
so we just add 
{ void StartMove(int x, int y); // set stx=x, sty=y
    void EndMove(int x, int y); // [2 marks] Move the center of the last shape containing point (stx,sty) to point (x,y)
                                //   and make this shape the last one (on top of all shapes)
    double GetArea(); // Get the area of the last shape
} 
