#ifndef ESP_FTP_LIB_H_
#define ESP_FTP_LIB_H_

#include <list>
#include <Arduino.h>

#include "FTPUser.h"
#include "FTPConnection.h"
#include "FTPFilesystem.h"

class FTPServer
{
public:
	FTPServer();
	virtual ~FTPServer();

	void addUser(const String & Username, const String & Password);
	void addUser(const FTPUser & User);

	void addFilesystem(String Name, FS * const Filesystem);

	bool end();
    bool begin();
	void handle();

	size_t countConnections() const;

private:
	WiFiServer _Server;

	std::list<FTPUser> _UserList;
	std::list<std::shared_ptr<FTPConnection>> _Connections;

	FTPFilesystem _Filesystem;
};

#endif
