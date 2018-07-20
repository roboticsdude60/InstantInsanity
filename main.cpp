#include <iostream>
#include "Cube.h"
#include <list>
#include <set>
#include <stack>
#include <cmath>


using namespace std;

const bool isTowerComplete(list<Cube*> stack);

const bool isTowerValid(list<Cube*> stack);

int numOfCubes = 4;

int main() {

   Cube* cube1 = new Cube(red, green, blue, blue, green, white);
   Cube* cube2 = new Cube(red, green, white, red, blue, white);
   Cube* cube3 = new Cube(blue, red, red, red, green, white);
   Cube* cube4 = new Cube(blue, white, green, white, red, blue);


   stack<Cube*> allUnusedCubes;
   allUnusedCubes.push(cube1);
   allUnusedCubes.push(cube2);
   allUnusedCubes.push(cube3);
   allUnusedCubes.push(cube4);

   list<Cube*> cubesTower;

//   cubesTower.emplace_back(allUnusedCubes.top());
//   allUnusedCubes.pop();

   //FIXME will get stuck in endless loop if no solution found
   while (!isTowerComplete(cubesTower)) {
      if (isTowerValid(cubesTower) || cubesTower.size() == 0) {
         cubesTower.emplace_back(allUnusedCubes.top());
         allUnusedCubes.pop();
         cubesTower.back()->orientation = 0;
      }

      while (!isTowerValid(cubesTower) && cubesTower.back()->orientation < 24) {
         cubesTower.back()->NextOrientation();
      }
      if (cubesTower.back()->orientation > 23) {
         Cube* topCube = cubesTower.back();
         allUnusedCubes.push(topCube);
         cubesTower.pop_back();
         cubesTower.back()->NextOrientation();

      }
   }

   for (Cube* c:cubesTower) {
      cout << c->toString() << endl;
   }

   return 0;
}


const bool isTowerValid(list<Cube*> stack) {
   set<Colors> left, right, front, back;
   for (Cube* c: stack) {
      left.insert(c->left);
      right.insert(c->right);
      front.insert(c->front);
      back.insert(c->back);
   }
   return stack.size() == min(min(left.size(), right.size()), min(front.size(), back.size() ));
}

const bool isTowerComplete(list<Cube*> stack) {
   return stack.size() == numOfCubes && isTowerValid(stack);
}
