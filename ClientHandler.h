#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

template <typename T, typename S>
class ClientHandler {
public:
    virtual void handleClient(int) = 0;
    virtual ClientHandler* clone() = 0;
};
#endif //EX4_CLIENTHANDLER_H
