/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:09:37 by tdutel            #+#    #+#             */
/*   Updated: 2024/04/29 16:15:37 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "Irc.hpp"

class Client;
class Server;
class Channel;
		void	fctPASS(std::string str, Server& server, Client& client);
		void	fctUSER(std::string str, Server& server, Client& client);
		void	fctNICK(std::string str, Server& server, Client& client);
		void	fctJOIN(std::string str, Server& server, Client& client);

class Server
{

//############################# PRIVATE ##########################################################//
	private:
//----------------------------- ATTRIBUTS ----------------------------------------------------------//

		uint64_t 														_port;
		const std::string 												_servName;
		const std::string												_pass;
		int																_n;

	//----	EPOLL ATTRIBUTS	----//
		int 															_epoll_fd;
		int																_server_fd;
		struct sockaddr_in												_server_addr;
		socklen_t														_addrLen;
		struct epoll_event												_event;
		struct epoll_event												_events[MAX_EVENTS];
		int																_nfds;

	//----	MAP	----//
		std::map<int, Client*>											_mapClient;
		std::map<std::string, void(*) (std::string, Server&, Client&)>	_commandList;
		// std::map<std::string, Channel*>									_mapChannel;


//----------------------------- FUNCTIONS ----------------------------------------------------------//

	//----	EPOLL FCT	----//
		void										epollCreation();
		void										socketCreation();
		void										addrConfig();
		void										linkSocket();
		void										listenConnectIn();
		void										addSocketToEpoll();
		void										eventLoop(int n);

		void										epollinEvent(int n);
		void										epollrdhupEvent(int n);
		void										epolloutEvent(int n);
		void										closeFd();

	//----	UTILS	----//
		void										initCommand();
		std::vector<std::string>					splitStr(char *str, std::string sep);
		std::vector< std::vector<std::string> >		splitVector(std::vector<std::string> &line, std::string sep);


//############################# PUBLIC ##########################################################//

	public:
		std::map<std::string, Channel*>									_mapChannel;
		//todo: mettre mapChannel en private et essayer de mettre les commandes fct en fonction membre de server"

		Server(char *port);
		Server(char *port, const std::string& pass);
		~Server();
		void										epollWait();

		std::string									getPass();
		bool										nickAlreadyUsed(const std::string& str);

		//TODO creer une fonction pour kick le client (fonction public pour pouvoir l'appeler depuis fctPASS())
		void	kickClient(int fd);
		//		FCT_COMMANDLIST		//
		// int							cmdCheck(char *buffer);
		// void						cmdMode(char *buffer);
};

#endif
