#include <iostream>

struct Unit; //����������� ���������� ��� ����������� typedef-��

//��������� �� ����������� ���� ������ Unit
typedef const unsigned Unit::* c_Unit_ptr;
//��������� ����������� ����� ������ Unit, ��� ����������, ������������ unsigned
typedef unsigned (Unit::* m_Unit_ptr)() const;

struct Unit {

    Unit() : _id(0), _hp(0) {};                           //����������� �� ���������(������)
    Unit(unsigned id, unsigned hp) : _id(id), _hp(hp) {}; //����������� �� ���� ����������

    unsigned id() const { return _id; } //������� ���������� ������
    static c_Unit_ptr return_HP() { return &Unit::_hp; }
    //����������� �����, ������������ ��������� �� ����������� ���� ������ Unit

private:            //������ ���� ����������
    const unsigned _id; //������� �������������
    const unsigned _hp; //��������� �� ���� ������ Unit ��� ������ ��� �� ��������
};

//�������� ��������� �� ����� ������ Unit
m_Unit_ptr method_ptr = &Unit::id;
//�������� ��������� �� ����������� ����� ������ Unit
c_Unit_ptr(*s_method)() = &Unit::return_HP;
//�������� ��������� �� ����������� ���� ������ Unit,
//������������� ��������� �� ����������� ����� ������ Unit,
//� ��� ����� ��� �������, ��� ���� ���������, 
//������� ��� ����� ������� �� ��������� ���� ����� Unit
c_Unit_ptr field_ptr = (*s_method)();

//���������� ���������� ��� typedef-��
//unsigned (Unit::*method_ptr)() const = &Unit::id;
//�� ��������� � ��������� ����� ������
//const unsigned  Unit::*field_ptr = &Unit::_hp;


int main()
{
    //������������� �������
    Unit u(15, 100);
    Unit* u_ptr = &u;

    //�������� ����������������� ������������ ������
    //c_Unit_ptr new_field_ptr  = Unit::return_HP(); 

    //����� ����������� ������ ���������� �� �����
    std::cout << (u.*method_ptr)() << ' ' << (u_ptr->*method_ptr)() << '\n';
    std::cout << u.*field_ptr << ' ' << (u_ptr->*field_ptr) << '\n';

    return 0;
}