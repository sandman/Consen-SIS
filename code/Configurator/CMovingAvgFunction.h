// �����Ϳ������á������ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CMovingAvgFunction ��װ��

class CMovingAvgFunction : public COleDispatchDriver
{
public:
	CMovingAvgFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CMovingAvgFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CMovingAvgFunction(const CMovingAvgFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IMovingAvgFunction ����
public:
	BOOL get_Weighted()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Weighted(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IMovingAvgFunction ����
public:

};