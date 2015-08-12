//
// Created by xyiyy on 2015/8/10.
//

#ifndef JHELPER_EXAMPLE_PROJECT_P_HPP
#define JHELPER_EXAMPLE_PROJECT_P_HPP


const double EPS = 1e-9;

class P{
public:
    double x,y;
    P(){}
    P(double _x,double _y){
        x = _x;y=_y;
    }
    double add(double a, double b){
        if(fabs(a+b)<EPS*(fabs(a) + fabs(b)))return 0;
        return  a+b;
    }

    P  operator + (const P &p){
        return P(add(x,p.x),add(y,p.y));
    }

    P operator - (const P &p){
        return P(add(x,-p.x),add(y,-p.y));
    }

    P operator *(const double &d){
        return P(x*d,y*d);
    }

    P operator /(const double &d){
        return P(x/d,y/d);
    }

    double dot(P p){
        return add(x*p.x,y*p.y);
    }

    double  det(P p){
        return add(x*p.y,-y*p.x);
    }

    //�жϵ��Ƿ����߶���
    bool on_seg(P p1,P p2,P q){
        return (p1-q).det(p2-q) == 0 &&(p1-q).dot(p2-q)<=0;
    }

    //�������߶εĽ���
    P intersection(P p1, P p2, P q1,P q2){
        return p1 + (p2-p1)*((q2-q1).det(q1-p1)/(q2-q1).det(p2-p1));
    }

    double abs(){
        return sqrt(abs2());
    }

    double abs2(){
        return dot(*this);
    }
    //��ԭ����ת�Ƕ�B������ֵ�������µĵ�
    P rot(double rad){
        return P(add(x*cos(rad),-y*sin(rad)),add(x*sin(rad),y * cos(rad)));
    }
    P rot90(){
        return P(-y,x);
    }
    bool equals(P p){
        return compareTo(p) == 0;
    }
    int compareTo(P p){
        int b = sig(x-p.x);
        if(b!=0)return b;
        return sig(y-p.y);
    }
    int sig(double x){
        if(fabs(x)<EPS)return 0;
        return  x < 0 ? -1 : 1;
    }

    //�߶��ཻ�ж�
    bool crsSS(P p1,P p2,P q1,P q2){
        if(max(p1.x, p2.x) + EPS < min(q1.x, q2.x))return false;
        if(max(q1.x, q2.x) + EPS < min(p1.x, p2.x))return false;
        if(max(p1.y, p2.y) + EPS < min(q1.y, q2.y))return false;
        if(max(q1.y, q2.y) + EPS < min(p1.y, p2.y))return false;
        /*(if((p1 - p2).det(q1 - q2) == 0){
            return (on_seg(p1,p2,q1) || on_seg(p1,p2,q2) || on_seg(q1,q2,p1) || on_seg(q1,q2,p2));
        }else{
            P r = intersection(p1,p2,q1,q2);
            return on_seg(p1,p2,r) && on_seg(q1,q2,r);

        }*/
        return (p2 - p1).det(q1 - p1) * (p2 - p1).det(q2 - p1) <= 0
               && (q2 - q1).det(p1 - q1) * (q2 - q1).det(p2 - q1) <= 0;
    }

    //ֱ�ߺ��߶��ཻ�ж�
    bool crsLS(P l1,P l2,P s1,P s2){
        return (s1 - l2).det(l1 - l2) * (s2 - l2).det(l1 - l2) <= 0;
    }

    //ֱ���ཻ�ж�
    //����-1��ʾ�غϣ�0��ʾƽ�У�1��ʾ�ཻ
    int crsLL(P p1,P p2,P q1,P q2){
        if(sig((p1 - p2).det(q1 - q2)) != 0)return 1;
        if(sig((p1 - q2).det(q1 - p2)) != 0)return 0;
        return -1;
    }

    //ֱ�ߺ�ֱ�ߵĽ���
    /*P isLL(P p1,P p2,P q1,P q2){
        double d = (q2 - q1).det(p2 - p1);
        if(sig(d)==0)return NULL;
        return intersection(p1,p2,q1,q2);
    }*/

    //�㵽ֱ�ߵĴ���
    P proj(P p1,P p2,P q){
        return p1 + ((p2 - p1) * ((p2 -p1).dot(q - p1) / (p2 - p1).abs2()));
    }

    //�߶ε���ľ���
    double disSP(P p1,P p2,P q){
        if((p2 - p1).dot(q - p1) <= 0)return (q - p1).abs();
        if((p1 - p2).dot(q - p2) <= 0)return (q - p2).abs();
        return disLP(p1,p2,q);
    }

    //ֱ�ߵ���ľ���
    double disLP(P p1,P p2,P q){
        return fabs((p2 - p1).det(q - p1)) / (p2 - p1).abs();
    }

    //Բ���߶��ཻ���ж�
    bool crsCS(P c,double r,P p1,P p2){
        return disSP(p1,p2,c)<r + EPS && (r < (c-p1).abs() + EPS || r < (c - p2).abs() + EPS);
    }

    //Բ��Բ�ཻ���ж�
    bool crsCC(P c1,double r1,P c2,double r2){
        double dis = (c1 - c2).abs();
        return dis < r1 + r2 + EPS && fabs(r1 - r2) < dis + EPS;
    }

    //�ĵ㹲Բ�ж�
    /*bool onC(P p1,P p2,P p3,P p4){
        P c = CCenter(p1,p2,p3);
        if(c == NULL) return false;
        return add((c - p1).abs2(), -(c - p4).abs2()) == 0;
    }*/

    //���㹲Բ��Բ��
    /*P CCenter(P p1,P p2,P p3){
        //if(disLP(p1, p2, p3) < EPS)return NULL;//���㹲��
        P q1 = (p1 + p2) * 0.5;
        P q2 = q1 + ((p1 - p2).rot90());
        P s1 = (p3 + p2) * 0.5;
        P s2 = s1 + ((p3 - p2).rot90());
        return isLL(q1,q2,s1,s2);
    }*/


};



#endif //JHELPER_EXAMPLE_PROJECT_P_HPP
