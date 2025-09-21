attribute highp vec4 qt_Vertex;
attribute highp vec4 qt_Color;

varying highp vec4 qt_Color0;

void main(void)
{
    gl_Position = qt_Vertex;
    qt_Color0 = qt_Color;
}
