#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>

cv::Mat CarregarImagem(std::string caminho) {
    cv::Mat imagem = cv::imread(caminho);
    if(imagem.empty()){
        std::cout << "Foto nao encontrada" << std::endl;
        return cv::Mat();
    }
    return imagem;
}

std::vector<cv::Mat> ComponentesCor(cv::Mat imagem) {


    // SÉPIA

    cv::Mat img1 = cv::Mat::zeros(imagem.size(), imagem.type());

    cv::Mat kernelSepia = (cv::Mat_<float>(3, 3) <<
    0.131f, 0.534f, 0.272f,
    0.168f, 0.686f, 0.349f,
    0.189f, 0.769f, 0.393f
    );

    cv::transform(imagem, img1, kernelSepia);

    // GRANULADA

    cv::Mat img2 = cv::Mat::zeros(imagem.size(), imagem.type());

    cv::Mat ruido = cv::Mat::zeros(imagem.size(), imagem.type());

    cv::randn(ruido,
              cv::Scalar(0, 0, 0),
              cv::Scalar(30, 30, 30));

    cv::add(imagem, ruido, img2);


    // MAIS ROXA
    cv::Mat img3 = cv::Mat::zeros(imagem.size(), imagem.type());

    int mapa3[] = {
        2, 0,   // R -> B
        0, 2    // B -> R
    };

    cv::mixChannels(&imagem, 1, &img3, 1, mapa3, 2);


    return {img1, img2, img3};
}

std::vector<cv::Mat> ElementosCor(cv::Mat imagem) {
    cv::Mat imagemcinza, imagemrgb, imagemhsv, imagembgr;

    // BGR → escala de cinza
    cv::cvtColor(imagem, imagemcinza, cv::COLOR_BGR2GRAY);

    // BGR → RGB
    cv::cvtColor(imagem, imagemrgb, cv::COLOR_BGR2RGB);

    // BGR → HSV
    cv::cvtColor(imagem, imagemhsv, cv::COLOR_BGR2HSV);

    // RGB → BGR
    cv::cvtColor(imagemrgb, imagembgr, cv::COLOR_RGB2BGR);

    // Cinza (1 canal) → BGR (3 canais)
    // Necessário para poder concatenar com as imagens de 3 canais
    cv::cvtColor(imagemcinza, imagemcinza, cv::COLOR_GRAY2BGR);

    return {imagemcinza, imagemrgb, imagemhsv, imagembgr};
}

int main(){
    std::string caminhoimagem = "imagens/dogfofa.jpg"; // Substitua pelo seu arquivo real
    cv::Mat imagem = CarregarImagem(caminhoimagem);

    // Se a imagem não carregou, encerra o programa para não dar erro depois
    if(imagem.empty()) return -1;

    // Recebe e extrai as 3 imagens com canais trocados
    std::vector<cv::Mat> comps = ComponentesCor(imagem);
    cv::Mat imagem1 = comps[0];
    cv::Mat imagem2 = comps[1];
    cv::Mat imagem3 = comps[2];

    // Recebe e extrai a imagem cinza e a RGB
    std::vector<cv::Mat> elems = ElementosCor(imagem);
    cv::Mat imagemc = elems[0];
    cv::Mat imagemr = elems[1];
    cv::Mat imagemh = elems[2];
    cv::Mat imagemb = elems[3];

    // Monta o painel
    cv::Mat linha1, linha2, painelFinal;
    cv::hconcat(std::vector<cv::Mat>{imagem, imagem1, imagem2, imagem3}, linha1);
    cv::hconcat(std::vector<cv::Mat>{imagemc, imagemr, imagemh, imagemb}, linha2);
    cv::vconcat(linha1, linha2, painelFinal);

    // Exibe tudo de uma vez
    cv::namedWindow("Script 2", cv::WINDOW_NORMAL);
    cv::imshow("Script 2", painelFinal);
    cv::waitKey(0);

    return 0;
}
