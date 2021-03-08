#include <iostream>
#include <vector>
#include <fstream>

#include <bar.h>
#include <freezer.h>
#include <sinuca.h>
#include <sanfona.h>
#include <oculos.h>

vector<Objeto*> objetos_cena;
int pos_selecionado = -1;

using namespace std;

void salvar_arquivo()
{
    ofstream arquivo("../objetos.txt");

    if (arquivo.is_open()) {
        if (objetos_cena.empty()) {
            cout << "Sem objetos em cena para salvar" << endl;
        } else {
            for (int i = 0; i < objetos_cena.size(); i++) {
                arquivo << objetos_cena[i]->nome << " ";

                arquivo << objetos_cena[i]->tr.x << " ";
                arquivo << objetos_cena[i]->tr.y << " ";
                arquivo << objetos_cena[i]->tr.z << " ";

                arquivo << objetos_cena[i]->rt.x << " ";
                arquivo << objetos_cena[i]->rt.y << " ";
                arquivo << objetos_cena[i]->tr.z << " ";

                arquivo << objetos_cena[i]->sc.x << " ";
                arquivo << objetos_cena[i]->sc.y << " ";
                arquivo << objetos_cena[i]->sc.z << endl;

                cout << "Objeto salvo" << endl;
            }
        }

        arquivo.close();
    } else {
        cout << "Erro de leitura" << endl;
    }
}

void carregar_arquivo()
{
    ifstream arquivo("../objetos.txt");

    if(!arquivo) {
        cout << "Erro de leitura" << endl;
    }

    string nome_objeto = "";
    float tr_x = 0, tr_y = 0, tr_z = 0;
    float rt_x = 0, rt_y = 0, rt_z = 0;
    float sc_x = 1, sc_y = 1, sc_z = 1;

    Vetor3D tr_ = Vetor3D(0,0,0);
    Vetor3D rt_ = Vetor3D(0,0,0);
    Vetor3D sc_ = Vetor3D(1,1,1);

    while(!arquivo.eof()) {
        arquivo >> nome_objeto;

        if (nome_objeto == "bar") {
            arquivo >> tr_x >> tr_y >> tr_z;
            arquivo >> rt_x >> rt_y >> rt_z;
            arquivo >> sc_x >> sc_y >> sc_z;

            Bar* bar = new Bar ();

            bar->tr.x = tr_x;
            bar->tr.y = tr_y;
            bar->tr.z = tr_z;

            bar->rt.x = rt_x;
            bar->rt.y = rt_y;
            bar->rt.z = rt_z;

            bar->sc.x = sc_x;
            bar->sc.y = sc_y;
            bar->sc.z = sc_z;

            objetos_cena.push_back(bar);
        } else if (nome_objeto == "freezer") {
//            arquivo >> tr_x >> tr_y >> tr_z;
//            arquivo >> rt_x >> rt_y >> rt_z;
//            arquivo >> sc_x >> sc_y >> sc_z;

//            freezer->tr.x = tr_x;
//            freezer->tr.y = tr_y;
//            freezer->tr.z = tr_z;

//            freezer->rt.x = rt_x;
//            freezer->rt.y = rt_y;
//            freezer->rt.z = rt_z;

//            freezer->sc.x = sc_x;
//            freezer->sc.y = sc_y;
//            freezer->sc.z = sc_z;

            arquivo >> tr_.x >> tr_.y >> tr_.z;
            arquivo >> rt_.x >> rt_.y >> rt_.z;
            arquivo >> sc_.x >> sc_.y >> sc_.z;

            Freezer* freezer = new Freezer ();

            freezer->tr = tr_;
            freezer->rt = rt_;
            freezer->sc = sc_;

            objetos_cena.push_back(freezer);
        } else if (nome_objeto == "oculos") {
            arquivo >> tr_x >> tr_y >> tr_z;
            arquivo >> rt_x >> rt_y >> rt_z;
            arquivo >> sc_x >> sc_y >> sc_z;

            Oculos* oculos = new Oculos ();

            oculos->tr.x = tr_x;
            oculos->tr.y = tr_y;
            oculos->tr.z = tr_z;

            oculos->rt.x = rt_x;
            oculos->rt.y = rt_y;
            oculos->rt.z = rt_z;

            oculos->sc.x = sc_x;
            oculos->sc.y = sc_y;
            oculos->sc.z = sc_z;

//            arquivo >> tr_.x >> tr_.y >> tr_.z;
//            arquivo >> rt_.x >> rt_.y >> rt_.z;
//            arquivo >> sc_.x >> sc_.y >> sc_.z;

//            oculos->tr = tr_;
//            oculos->rt = rt_;
//            oculos->sc = sc_;

            objetos_cena.push_back(oculos);
        } else if (nome_objeto == "sanfona") {
            arquivo >> tr_.x >> tr_.y >> tr_.z;
            arquivo >> rt_.x >> rt_.y >> rt_.z;
            arquivo >> sc_.x >> sc_.y >> sc_.z;

            Sanfona* sanfona = new Sanfona ();

            sanfona->tr = tr_;
            sanfona->rt = rt_;
            sanfona->sc = sc_;

            objetos_cena.push_back(sanfona);
        } else if (nome_objeto == "sinuca") {
            arquivo >> tr_.x >> tr_.y >> tr_.z;
            arquivo >> rt_.x >> rt_.y >> rt_.z;
            arquivo >> sc_.x >> sc_.y >> sc_.z;

            Sinuca* sinuca = new Sinuca ();

            sinuca->tr = tr_;
            sinuca->rt = rt_;
            sinuca->sc = sc_;

            objetos_cena.push_back(sinuca);
        }
    }
}

void cena()
{
    GUI::displayInit();

    GUI::setLight(1,1,3,5,true,false);
    GUI::setLight(2,-1.5,0.5,-1,true,false);

    GUI::setColor(0.34,0.2,0.08);
    GUI::drawFloor();

    for (int i = 0; i < objetos_cena.size(); ++i) {
        glPushMatrix();
            objetos_cena[i]->desenhar();
        glPopMatrix();
    }

    if (pos_selecionado >= 0 and pos_selecionado < objetos_cena.size()) {
        objetos_cena[pos_selecionado]->tr.x += glutGUI::dtx;
        objetos_cena[pos_selecionado]->tr.y += glutGUI::dty;
        objetos_cena[pos_selecionado]->tr.z += glutGUI::dtz;

        objetos_cena[pos_selecionado]->rt.x += glutGUI::dax;
        objetos_cena[pos_selecionado]->rt.y += glutGUI::day;
        objetos_cena[pos_selecionado]->rt.z += glutGUI::daz;

        objetos_cena[pos_selecionado]->sc.x += glutGUI::dsx;
        objetos_cena[pos_selecionado]->sc.y += glutGUI::dsy;
        objetos_cena[pos_selecionado]->sc.z += glutGUI::dsz;
    }

    GUI::displayEnd();
}

void interacao(unsigned char entrada, int mouse_x, int mouse_y)
{
    GUI::keyInit(entrada, mouse_x, mouse_y);

    switch (entrada) {
    //Inserção
    case '/':
        objetos_cena.push_back(new Bar ());
        break;
    case ']':
        objetos_cena.push_back(new Freezer ());
        break;
    case '[':
        objetos_cena.push_back(new Oculos ());
        break;
    case '.':
        objetos_cena.push_back(new Sinuca ());
        break;
    case ',':
        objetos_cena.push_back(new Sanfona ());
        break;
    //Alternância
    case '+': /*Próximo*/
        if (pos_selecionado >= 0 and pos_selecionado < objetos_cena.size()) {
            objetos_cena[pos_selecionado]->selecionado = false;
            objetos_cena[pos_selecionado]->desenha_eixos = false;
        }
        pos_selecionado++;
        pos_selecionado = pos_selecionado % objetos_cena.size();
        if (pos_selecionado >= 0 and pos_selecionado < objetos_cena.size()) {
            objetos_cena[pos_selecionado]->selecionado = true;
            objetos_cena[pos_selecionado]->desenha_eixos = true;
        }
        break;
    case '-': /*Anterior*/
        if (pos_selecionado >= 0 and pos_selecionado < objetos_cena.size()) {
            objetos_cena[pos_selecionado]->selecionado = false;
            objetos_cena[pos_selecionado]->desenha_eixos = false;
        }
        pos_selecionado--;
        if (pos_selecionado < 0) {
            pos_selecionado = objetos_cena.size()-1;
        }
        if (pos_selecionado >= 0 and pos_selecionado < objetos_cena.size()) {
            objetos_cena[pos_selecionado]->selecionado = true;
            objetos_cena[pos_selecionado]->desenha_eixos = true;
        }
        break;
    //Exclusão
    case 8: /*Backspace*/
        if (!objetos_cena.empty()) {
            cout << pos_selecionado << " " << objetos_cena.at(pos_selecionado)->nome << " fora de cena" << endl;
            objetos_cena.erase(objetos_cena.begin() + (pos_selecionado));
        }
        break;
    //Arquivo
    case '>':
        salvar_arquivo();
        break;
    case '<':
        carregar_arquivo();
        break;
    //Padrões
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;
    default:
        break;

    }
}

int main()
{
    GUI gui = GUI(800,600,cena,interacao);
    return 0;
}
