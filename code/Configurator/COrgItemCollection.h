// �����Ϳ������á������ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// COrgItemCollection ��װ��

class COrgItemCollection : public COleDispatchDriver
{
public:
	COrgItemCollection(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	COrgItemCollection(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	COrgItemCollection(const COrgItemCollection& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IOrgItemCollection ����
public:
	LPDISPATCH get_Items(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}

	// IOrgItemCollection ����
public:

};