The builder method is useful when you require several steps (functions) to create the final resulting object.

Coding perspective:
1) An abstract builder: This specifies the steps (or virtual functions) to build the final concrete product
        Concrete builder: Inherited from abstract builder, and specifies the concrete functions to build the object.
        
2) Director: The Director is only responsible for executing the building steps (or calling the functions of concrete class) in a particular sequence or order.
             Strictly speaking, the Director class is optional, since the client can control builders directly.
           
3) Client: The client code calls the director creating a builder object, passes it to the director and then initiates the construction process. 
           The end result is retrieved from the builder object.
