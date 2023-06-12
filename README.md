##Title: RPC Student Registration Implementation with Networking
This project showcases a distributed system implemented using Remote Procedure Call (RPC) paradigm in C. It includes a server and client application for student registration. The server handles registration requests from multiple clients concurrently, while the client sends registration data to the server. The RPC mechanism is used for communication between the server and client, enabling seamless remote procedure invocation. The code demonstrates the use of sockets, message passing, and serialization using XDR (External Data Representation) for data exchange. Explore the code to understand the fundamentals of RPC and network programming in C

Features:

    RPC implementation using C language
    Client-Server architecture for remote function invocation
    Robust error handling and input validation

Technologies Used:

    C programming language
    RPC (Remote Procedure Call)
    Networking using sockets

Instructions:

    Clone the repository and navigate to the project directory.
    Build the server using the provided Makefile: make server
    Start the server: ./server
    Build the client using the Makefile: make client
    Run the client: ./client

Feel free to explore the code, experiment with different inputs, and expand the functionality as per your requirements. Enjoy learning about RPC and networking with this project!
