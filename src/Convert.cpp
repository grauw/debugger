#include "Convert.h"
#include <QString>

int stringToValue( const QString& str )
{
	QString s = str.trimmed();
	int base = 10;
	
	// find base prefix or postfix
	if( s.startsWith("&" ) ) {
		switch( s[1].toUpper().toAscii() ) {
			case 'H':
				base = 16;
				break;
			case 'B':
				base = 2;
				break;
			case 'O':
				base = 8;
				break;
		}
		s = s.remove(0, 2);
	} else if( s.startsWith("#") || s.startsWith("$") ) {
		base = 16;
		s = s.remove(0, 1);
	} else if( s.startsWith("0x") ) {
		base = 16;
		s = s.remove(0, 2);
	} else if( s.startsWith("%") ) {
		base = 2;
		s = s.remove(0, 1);
	} else {
		switch( s.right(1)[0].toUpper().toAscii() ) {
			case 'H':
			case '#':
				base = 16;
				break;
			case 'B':
				base = 2;
				break;
			case 'O':
				base = 8;
				break;
		}
		if( base != 10 ) s.chop(1);
	}
	// convert value
	bool ok;
	int value = s.toInt( &ok, base );
	if( ok )
		return value;
	else
		return -1;
}