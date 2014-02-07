#include <jni.h>
#include <string.h>
#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

// java�е�jstring, ת��Ϊc��һ���ַ�����
char*   Jstring2CStr(JNIEnv*   env,   jstring   jstr)
{
	 char*   rtn   =   NULL;
	 jclass   clsstring   =   (*env)->FindClass(env,"java/lang/String");
	 jstring   strencode   =   (*env)->NewStringUTF(env,"GB2312");
	 jmethodID   mid   =   (*env)->GetMethodID(env,clsstring,   "getBytes",   "(Ljava/lang/String;)[B");
	 jbyteArray   barr=   (jbyteArray)(*env)->CallObjectMethod(env,jstr,mid,strencode); // String .getByte("GB2312");
	 jsize   alen   =   (*env)->GetArrayLength(env,barr);
	 jbyte*   ba   =   (*env)->GetByteArrayElements(env,barr,JNI_FALSE);
	 if(alen   >   0)
	 {
	  rtn   =   (char*)malloc(alen+1);         //new   char[alen+1]; "\0"
	  memcpy(rtn,ba,alen);
	  rtn[alen]=0;
	 }
	 (*env)->ReleaseByteArrayElements(env,barr,ba,0);  //�ͷ��ڴ�

	 return rtn;
}

//����ǩ��, Java���� �� ����native�������� �ز�����, ����Ĳ�������native�����Ĳ���
jint Java_shuliang_han_ndkparameterpassing_DataProvider_add(JNIEnv * env, jobject obj, jint x, jint y)
{
	//Java�е�int��Ӧ����C�����е�long����, ��ӦJNI�е�jint����, C������
	LOGI("JNI_log : x = %d , y = %d" , x , y);
	return x + y;
}


jstring Java_shuliang_han_ndkparameterpassing_DataProvider_sayHelloInc(JNIEnv *env, jobject obj, jstring str)
{
	char *p = (char*)Jstring2CStr(env, str);
	//��ӡJava���ݹ���������
	LOGI("Java JNI string parameter is : %s", p);
	
	char *append = "append";
	
	//strcat(dest, source) �������Խ�source�ַ��� ��ӵ�dest�ַ�������
	return (*env)->NewStringUTF(env, strcat(p, append));
}


jintArray Java_shuliang_han_ndkparameterpassing_DataProvider_intMethod(JNIEnv *env, jobject obj, jintArray arr)
{
	//��ȡarr��С
	int len = (*env)->GetArrayLength(env, arr);
	
	//��LogCat�д�ӡ��arr�Ĵ�С
	LOGI("the length of array is %d", len);
	
	//�������Ϊ0, ����arr
	if(len == 0)
		return arr;
		
	//������ȴ���0, ��ô��ȡ�����е�ÿ��Ԫ��
	jint* p = (*env)->GetIntArrayElements(env, arr, 0);
	
	//��ӡ��������ÿ��Ԫ�ص�ֵ
	int i = 0;
	for(; i < len; i ++)
	{
		LOGI("arr[%d] = %d", i, *(p + i));
	}
	
	return arr;
	
}

