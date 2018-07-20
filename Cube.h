//
// Created by jscholl4 on 1/9/18.
//

#ifndef MASONSCUBES_CUBE_H
#define MASONSCUBES_CUBE_H

#include <string>
using namespace std;

enum Colors {
   red, blue, white, green
};

class Cube {
public:
   Colors top, bottom, left, right, front, back;
   Cube(Colors top, Colors bottom, Colors left, Colors right, Colors front, Colors back);

   void NextOrientation();

   int orientation = 0;
   string toString();
private:
   void spinVertAxis();

   void flipUp();

   int spinCount = 0;
   int flipCount = 0;
};


#endif //MASONSCUBES_CUBE_H
