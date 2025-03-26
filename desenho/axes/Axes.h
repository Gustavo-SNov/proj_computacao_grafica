//
// Created by Gustavo Novais on 22/03/2025.
//

#ifndef AXES_H
#define AXES_H

class Axes {

public:
    float x,y,z;

public:
    Axes(float x, float y, float z);

    void drawAxes() const;
    void setConfigs() const;
};



#endif //AXES_H
