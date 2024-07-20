/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Numeric_replies.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:39:21 by tdutel            #+#    #+#             */
/*   Updated: 2024/07/20 14:36:42 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMERIC_REPLY_HPP
# define NUMERIC_REPLY_HPP


# define RPL_WELCOME 001
# define RPL_YOURHOST 002
# define RPL_CREATED 003
# define RPL_MYINFO 004
# define RPL_ISUPPORT 005
# define RPL_LUSERCLIENT 251
# define RPL_LUSEROP 252
# define RPL_LUSERME 255

# define RPL_CHANNELMODEIS 324
# define RPL_NOTOPIC 331
# define RPL_TOPIC 332
# define RPL_INVITING 341
# define RPL_NAMREPLY 353
# define RPL_ENDOFNAMES 366

# define RPL_MOTD 372
# define RPL_MOTDSTART 375
# define RPL_ENDOFMOTD 376

# define ERR_NOSUCHNICK 401
# define ERR_NOSUCHCHANNEL 403
# define ERR_CANNOTSENDTOCHAN 404
# define ERR_TOOMANYCHANNELS 405
# define ERR_NOTEXTTOSEND 412 
# define ERR_ERRONEUSNICKNAME 432
# define ERR_NICKNAMEINUSE 433

# define ERR_USERNOTINCHANNEL 441
# define ERR_NOTONCHANNEL 442
# define ERR_USERONCHANNEL 443
# define ERR_NEEDMOREPARAMS 461
# define ERR_ALREADYREGISTERED 462
# define ERR_PASSWDMISMATCH 464
# define ERR_CHANNELISFULL 471
# define ERR_INVITEONLYCHAN 473
# define ERR_BANNEDFROMCHAN 474
# define ERR_BADCHANNELKEY 475
# define ERR_BADCHANMASK 476
# define ERR_CHANOPRIVSNEEDED 482
# define ERR_UMODEUNKNOWNFLAG 501

# define ERR_INVALIDKEY 525


#endif
