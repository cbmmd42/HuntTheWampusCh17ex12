#ifndef ILOCATION_HPP
#define ILOCATION_HPP

class ILocation{
	public:
	virtual int roomNumber() = 0;
	virtual ILocation* goThroughTunnel(int i) = 0;
	virtual std::string thingStr() = 0;
	virtual bool isConnected(int roomNumber) = 0;
	virtual int findTunnelNoFromRoomNo(int roomNo) = 0;
};


#endif /*ILOCATION_HPP*/