// �����Ϳ������á������ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CContrastFilter ��װ��

class CContrastFilter : public COleDispatchDriver
{
public:
	CContrastFilter(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CContrastFilter(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CContrastFilter(const CContrastFilter& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IContrastFilter ����
public:
	BOOL get_Percent()
	{
		BOOL result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Percent(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Amount()
	{
		long result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Amount(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IContrastFilter ����
public:

};