#ifndef MESH_H
#define MESH_H

#include <QVector>
#include <QVector2D>

class Mesh
{
public:
    Mesh();
    QVector<QVector2D> *vertices = new QVector<QVector2D>;
};

#endif // MESH_H
