# RSA_Communicating

This toy demo is used as a practice of RSA coding and decoding and tcp program.

The basic task is to implement a server and a client who communicate with each other using RSA to code and decode the message.

Version 1 implemented the tcp communicating of the server and the client, and completed the RSA coding and decoding function.

Version 2 dealt with some bugs of wrong message, turned some of the operations of the tcp coding into functios to simplified the progress.

Version 3 dealt with some bugs met in Version 1 and Version 2, integrate the tcp communicating functions into class, improved the RSA coding and decoding functions and used the functions to code and decode the message for the first time. Moreover, Version 3 introduced a transistor to bridge the server and the client. From now on the communicating of the server and the client is not directly between the two roles, and it should go through the transistor. The coding function in the RSA file adopted some ideas in computer network.

In Version 4 I want to implement the multi-thread communicating which allows multiple clients to communicate with the server at the same time. And in Version 5 I want to implement a star-like network which contains servers, a transistor and clients. Clients can communicate with each other, clients can request service from the servers and then the servers return the result to the clients. In Version 6 I want to implement some services of the servers.