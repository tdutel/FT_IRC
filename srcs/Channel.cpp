/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:00:08 by tdutel            #+#    #+#             */
/*   Updated: 2024/05/14 12:58:43 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Channel.hpp"

Channel::Channel(const std::string& name) : _name(name), _isMdp(false), _isUserLimit(false), _invitOnly(false)
{
}


Channel::Channel(const std::string& name, Client& mod) : _name(name), _isMdp(false), _isUserLimit(false), _invitOnly(false)
{
	addModerator(&mod);
}

Channel::~Channel()
{
}

std::size_t	Channel::getMemberSize()
{
	std::size_t size = _members.size();
	return (size);
}

std::map<std::string, Client *>	Channel::getMembers() const
{
	return (_members);
}

void	Channel::setName(std::string name)
{
	_name = name;
}

const std::string&	Channel::getName(void) const
{
	return (this->_name);
}

void	Channel::setTopic(std::string topic)
{
	_topic = topic;
}

const std::string&	Channel::getTopic(void) const
{
	return (this->_topic);
}

void	Channel::addMember(Client *newClient)
{
	if (_members.find(newClient->getNick()) == _members.end())	//ne l'ajoute pas si est déjà dedans
		_members[newClient->getNick()] = newClient;
	else
		throw ("from client NR : channel already joined !");
}

void	Channel::addModerator(Client *newClient)
{
	if (_moderators.find(newClient->getNick()) == _moderators.end())	//ne l'ajoute pas si est déjà dedans
		_moderators[newClient->getNick()] = newClient;
	else
		throw ("NR : client already is moderator");
}

void	Channel::addInvitMember(Client *newClient)
{
	if (_invitedMembers.find(newClient->getNick()) == _invitedMembers.end())	//ne l'ajoute pas si est déjà dedans
		_invitedMembers[newClient->getNick()] = newClient;
	else
		throw ("from client NR : channel already joined !");
}

bool	Channel::isMember(std::string client)
{
	if (_members.find(client) == _members.end())
		return (false);
	return (true);
}

bool	Channel::isModerator(std::string client)
{
	if (_moderators.find(client) == _moderators.end())
		return (false);
	return (true);
}

bool	Channel::isInvited(std::string client)
{
	if (_invitedMembers.find(client) == _invitedMembers.end())
		return (false);
	return (true);
}

void	Channel::rmMember(Client *client)
{
	if (_members.find(client->getNick()) != _members.end())	//ne le remove pas si est déjà remove
		_members.erase(client->getNick());
	else
		throw ("NR : client is not in the channel");
}

void	Channel::rmModerator(Client *client)
{
	if (_moderators.find(client->getNick()) != _moderators.end())	//ne le remove pas si est déjà remove
		_moderators.erase(client->getNick());
	else
		throw ("NR : client is not moderator");
}

void	Channel::rmInvitMember(Client *client)
{
	if (_invitedMembers.find(client->getNick()) != _invitedMembers.end())	//ne le remove pas si est déjà remove
		_invitedMembers.erase(client->getNick());
	else
		throw ("NR : client is not invited");
}

void	Channel::setUserLimit(int nb)
{
	_userLimit = nb;
	if (nb == 0)
		_isUserLimit = false;
	else
		_isUserLimit = true;
};

const int&	Channel::getUserLimit() const
{
	return (_userLimit);
};

void	Channel::setMdp(std::string	mdp)
{
	_mdp = mdp;
	if (mdp.empty())
		_isMdp = false;
	else
		_isMdp = true;
};

const std::string&	Channel::getMdp() const
{
	return (_mdp);
};

bool	Channel::getIsUserLimit()
{
	return (_isUserLimit);
};

bool	Channel::getIsMdp()
{
	return (_isMdp);
};

void	Channel::setInvitOnly(bool i)
{
	_invitOnly = i;
};

bool	Channel::getInvitOnly()
{
	return (_invitOnly);
};

void	Channel::setTopicRestriction(bool i)
{
	_topicRestriction = i;
};

bool	Channel::getTopicRestriction()
{
	return (_topicRestriction);
};
