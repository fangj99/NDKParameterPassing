package shuliang.han.ndkparameterpassing;

public class DataProvider {

	//��Java�е�����intֵ ����C����, ������Ӻ�, ����java���� shuliang.han.ndkparameterpassing.DataProvider
	public native int add(int x, int y);
	
	//��Java�ַ������ݸ�C����, C���Դ����ַ���֮��, �����������ظ�java
	public native String sayHelloInc(String s);
	
	//��java�е�int���鴫�ݸ�C����, C����Ϊÿ��Ԫ�ؼ�10, ���ظ�Java
	public native int[] intMethod(int[] nums); 
	
}
