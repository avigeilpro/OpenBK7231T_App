#ifndef __CONTROLLER_BL0942_H__
#define __CONTROLLER_BL0942_H__

#include "sim_local.h"
#include "Controller_Base.h"
#include "Coord.h"

class CControllerBL0942 : public CControllerBase {
	class CJunction *rx, *tx;
	class CText *txt_voltage, *txt_current, *txt_power;

	void setShapesActive(bool b);
	void setShapesFillColor(const CColor &c);
	float realCurrent;
	float realPower;
	float realVoltage;
public:
	CControllerBL0942() {
		rx = tx = 0;
		txt_voltage = txt_current = txt_power = 0;
		realCurrent = 0.25f;
		realPower = 60.0f;
		realVoltage = 220.0f;
	}
	CControllerBL0942(class CJunction *_rx, class CJunction *_tx, CText *_txt_voltage, CText *_txt_current, CText *_txt_power) {
		rx = _rx;
		tx = _tx;
		txt_voltage = _txt_voltage;
		txt_current = _txt_current;
		txt_power = _txt_power;
		realCurrent = 0.25f;
		realPower = 60.0f;
		realVoltage = 220.0f;
	}
	virtual void onDrawn();
	virtual class CControllerBase *cloneController(class CShape *origOwner, class CShape *newOwner);
};

#endif // __CONTROLLER_BL0942_H__
