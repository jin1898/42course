#pragma once
#ifndef ERRORCODES_HPP
# define ERRORCODES_HPP

enum ErrorCodes
{
	M_ERR_NOSUCHNICK = 401,
	M_ERR_NOSUCHCHANNEL = 403,
	M_ERR_CANNOTSENDTOCHAN = 404,
	M_ERR_UNKNOWNCOMMAND = 421,
	M_ERR_NOMOTD = 422,
	M_ERR_NONICKNAMEGIVEN = 431,
	M_ERR_ERRONEUSNICKNAME = 432,
	M_ERR_NICKNAMEINUSE = 433,
	M_ERR_USERNOTINCHANNEL = 441,
	M_ERR_NOTONCHANNEL = 442,
	M_ERR_USERONCHANNEL = 443,
	M_ERR_NOTREGISTERED = 451,
	M_ERR_NEEDMOREPARAMS = 461,
	M_ERR_ALREADYREGISTRED = 462,
	M_ERR_PASSWDMISMATCH = 464,
	M_ERR_YOUREBANNEDCREEP = 465,
	M_ERR_CHANNELISFULL = 471,
	M_ERR_BADCHANMASK = 476,
	M_ERR_UNKNOWNMODE = 472,
	M_ERR_INVITEONLYCHAN = 473,
	M_ERR_BANNEDFROMCHAN = 474,
	M_ERR_BADCHANNELKEY = 475,
	M_ERR_NOPRIVILEGES = 481,
	M_ERR_CHANOPRIVSNEEDED = 482,
	M_ERR_CANTKILLSERVER = 483,
	M_ERR_RESTRICTED = 484,
	M_ERR_UNIQOPPRIVSNEEDED = 485,
	M_ERR_NOOPERHOST = 491,
	M_ERR_UMODEUNKNOWNFLAG = 501,
	M_ERR_USERSDONTMATCH = 502
};
#endif
