Bridge design pattern separates an abstraction and its implementation.
Bridge is a structural design pattern that divides business logic or huge class into separate class hierarchies that can be developed independently.

One of these hierarchies (often called the Abstraction) will get a reference to an object of the second hierarchy (Implementation). 
The abstraction will be able to delegate some (sometimes, most) of its calls to the implementations object.
(Extract from: https://refactoring.guru/design-patterns/bridge)
