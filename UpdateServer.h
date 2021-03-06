/*
***************************************************************************  
**  Program  : UpdateServer.h, part of DSMRloggerWS
**  Version  : v1.0.4
** 
**  This is the ESP8266HTTPUpdateServer.h file 
**  modified by PA4WD ("https://github.com/PA4WD/Arduino/tree/master/libraries/ESP8266HTTPUpdateServer")
**
**  and then modified by Willem Aandewiel
**
***************************************************************************
*/


#ifndef __HTTP_UPDATE_SERVER_H
#define __HTTP_UPDATE_SERVER_H

#include <TelnetStream.h>       // Version 0.0.1 - https://github.com/jandrassy/TelnetStream

class ESP8266WebServer;

class ESP8266HTTPUpdateServer
{
  public:
    ESP8266HTTPUpdateServer(bool serial_debug=true);

    void setup(ESP8266WebServer *server)
    {
      setup(server, emptyString, emptyString);
    }

    void setup(ESP8266WebServer *server, const String& path)
    {
      setup(server, path, emptyString, emptyString);
    }

    void setup(ESP8266WebServer *server, const String& username, const String& password)
    {
      setup(server, "/update", username, password);
    }

    void setup(ESP8266WebServer *server, const String& path, const String& username, const String& password);

    void updateCredentials(const String& username, const String& password)
    {
      _username = username;
      _password = password;
    }

  protected:
    void _setUpdaterError();

  private:
    bool _serial_output;
    ESP8266WebServer *_server;
    String _username;
    String _password;
    bool _authenticated;
    String _updaterError;
  int _command;
};


#endif
