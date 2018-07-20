//
// Created by jscholl4 on 1/9/18.
//

#include "Cube.h"

#define ENUM_TO_STR(ENUM) std::string(#ENUM)

Cube::Cube(Colors top, Colors bottom, Colors left, Colors right, Colors front, Colors back)
   : top(top), bottom(bottom), left(left), right(right), front(front), back(back) {}

void Cube::NextOrientation() {
   //a total of 24 distinct orientations?
   if (spinCount == 3) {
      if ((flipCount % 2 == 0)) {
         flipUp();
      } else {
         //to alternate flipping up from the left and the right
         spinVertAxis();
         spinVertAxis();
         flipUp();
      }

   } else {
      spinVertAxis();
   }
   ++orientation;
}

void Cube::spinVertAxis() {
   Colors tmp = front;
   front = right;
   right = back;
   back = left;
   left = tmp;
   ++spinCount;
}

void Cube::flipUp() {
   Colors tmp = front;
   front = top;
   top = back;
   back = bottom;
   bottom = tmp;
   spinCount = 0;
   ++flipCount;
}

string enumToString(Colors c) {
   switch (c) {
      case green:
         return "green";
      case red:
         return "red";
      case blue:
         return "blue";
      case white:
         return "white";
      default:
         return "unknown color";
   }
}

string Cube::toString() {
   string cube;
   cube += enumToString(top) + " ";
   cube += enumToString(bottom) + " ";
   cube += enumToString(left) + " ";
   cube += enumToString(right) + " ";
   cube += enumToString(front) + " ";
   cube += enumToString(back) + " ";
   return cube;
}


