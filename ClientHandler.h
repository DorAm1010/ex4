#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

template <typename T, typename S>
/**
 * Incharge of communication protocol with the client.
 */
class ClientHandler {
public:
    /**
     * need to execute communication protocol,
     * until the end of connection.
     */
    virtual void handleClient(int) = 0;
    /**
     * creating a deep clone of client handler object.
     */
    virtual ClientHandler* clone() = 0;
};
#endif //EX4_CLIENTHANDLER_H
