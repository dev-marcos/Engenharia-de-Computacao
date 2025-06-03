#ifndef XADREZPIECE_H
#define XADREZPIECE_H

enum XadrezShape { NoShape, ZShape, SShape, LineShape, TShape, SquareShape,
                   LShape, MirroredLShape };

//! [0]
class Peca
{
public:
    Peca() { setShape(NoShape); }

    void setRandomShape();
    void setShape(XadrezShape shape);

    XadrezShape shape() const { return pieceShape; }
    int x(int index) const { return coords[index][0]; }
    int y(int index) const { return coords[index][1]; }
    int minX() const;
    int maxX() const;
    int minY() const;
    int maxY() const;
    Peca rotatedLeft() const;
    Peca rotatedRight() const;

private:
    void setX(int index, int x) { coords[index][0] = x; }
    void setY(int index, int y) { coords[index][1] = y; }

    XadrezShape pieceShape;
    int coords[4][2];
};
//! [0]

#endif
