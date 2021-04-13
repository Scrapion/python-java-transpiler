import java.util.ArrayList;
import java.util.Collections;
public class CLASSNAME{ 
public static void loose_code (   ) { 

  System.out.println( "INIZIO SCRIPT" );

 
 }public static String verDispari (  int num  ) { 
 if ( num % 2 == 0 ){ 

  return "PARI";

 }else{

  return "DISPARI";

 
 }}public static void doublePass (  String STRINGA ,  int num  ) { 
 if ( num<5 ){ 

  System.out.println( STRINGA );

 }else{

  System.out.println( num );
} 

 
 }public static void liste (   ) { 
 ArrayList  aaa = new ArrayList() ;

  aaa.add("UNO") ;

  aaa.add("DUE") ;

  aaa.add("TRE") ;

  Collections.reverse(aaa) ;

  int iter = 0 ;

  int size = aaa.size() ;

  for(;iter<size;iter++){

  System.out.println( popList(aaa,(aaa.size()-1)) );

 
 }}public static void main ( String []args ) { 
loose_code();
 int iter = 0 ;

  liste( );

  doublePass("MINORE DI 5",4);

  for(;iter<5;iter++){

  System.out.println( verDispari(iter)+"\n" );

 
 
 }}public static Object popList (ArrayList lst, int j) 
{
 Object temp = new Object();
 temp = lst.get(j);
 lst.remove(j);
 return temp;
}
public static ArrayList copyList ( ArrayList toCopy){
 ArrayList copy = new ArrayList();
copy.addAll(toCopy); 
 return copy;}   }
