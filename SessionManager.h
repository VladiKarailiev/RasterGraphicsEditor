#pragma once
#include "Session.h"


class SessionManager {
public:
    static void addSession(Session* session) { // const!!!!!!!!!
        sessions.pushBack(session);
    }

    static const Vector<Session*>& getSessions() {
        return sessions;
    }
    static Session* getSession(int id) {
        for (size_t i = 0; i < sessions.getSize(); i++)
        {
            if (sessions[i]->getId() == id) return sessions[i];
        }
        throw std::exception();
    }


    static void run();

    ~SessionManager()
    {
        for (size_t i = 0; i < sessions.getSize(); i++)
        {
            delete sessions[i];
        }
    }

private:
    static Vector<Session*> sessions; 
};
