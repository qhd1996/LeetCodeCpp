class Solution {
	typedef enum {
		NONE = 0,
		IP4 = '.',
		IP6 = ':'
	} IP_TYPE;

	IP_TYPE m_ipType;

	inline bool IsIP4Seg(char* begin, char* end) {
		int len = end - begin;
		if (len > 3) return false;
		if (len == 0) return false;
		if (*begin == '0' && len > 1) return false;
		
		for (int i = 0; i < len; ++i) {
			if (begin[i] < '0' || begin[i] > '9') return false;
		}
		if (len == 3) {
			if (*begin > '2') return false;
			if ((*(begin + 1) == '5') && (*(begin + 2) > '5')) return false;
		}
		return true;
	}
	inline bool IsValidNum(char ch) {
		if (ch >= '0' && ch <= '9') return true;
		if (ch >= 'A' && ch <= 'F') return true;
		if (ch >= 'a' && ch <= 'f') return true;
		return false;
	}
	inline bool IsIP6Seg(char* begin, char* end) {
		int len = end - begin;
		switch (len) {
			default:
			case 0:
				return false;
			case 1:
			case 2:
			case 3:
			case 4:
				for (int i = 0; i < len; ++i) {
					if (!IsValidNum(begin[i])) return false;
				}
				break;
		}
		return true;
	}
	inline bool UpdateType(IP_TYPE type, char*& begin, char*& end, int& segCount) {
		if (m_ipType == type || m_ipType == NONE) {
			end = begin = end + 1;
			m_ipType = type;
			++segCount;
			return true;
		}
		return false;
	}
public:
	string validIPAddress(string IP) {
		size_t len = IP.length();
		char* ch = const_cast<char*>(IP.c_str());
		char *begin = ch, *end = ch;
		m_ipType = NONE;
		int segCount = 1;

		while (*ch) {
			switch (*ch) {
			case '.':
				if (IsIP4Seg(begin, end) && UpdateType(static_cast<IP_TYPE>(*ch), begin, end, segCount)) {
					break;
				}
				return "Neither";
			case ':':
				if (IsIP6Seg(begin, end) && UpdateType(static_cast<IP_TYPE>(*ch), begin, end, segCount)) {
					break;
				}
				return "Neither";
			default:
				++end;
				break;
			}
			++ch;
		}
		
		switch (m_ipType) {
			case IP4:
				if (IsIP4Seg(begin, end) && (segCount == 4)) {
					return  "IPv4";
				}
				break;
			case IP6:
				if (IsIP6Seg(begin, end) && (segCount == 8))
					return "IPv6";
				break;
			default:
				break;;
		}
		return "Neither";
	}
};
