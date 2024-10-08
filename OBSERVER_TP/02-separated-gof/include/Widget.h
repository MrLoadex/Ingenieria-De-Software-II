#ifndef WIDGET_H
#define WIDGET_H

/****************************************WIDGET INTERFACE********************************/
class Widget
{
    public:
        virtual ~Widget() {}
        virtual void Draw() = 0;
};


#endif // WIDGET_H
