#include <QCoreApplication>
#include <QDebug>
#include "src/dl_dxf.h"
#include "src/dl_creationadapter.h"
#include "src/dl_attributes.h"
#include "src/dl_codes.h"
#include "src/dl_entities.h"
#include "src/dl_exception.h"
#include "src/dl_global.h"
#include "src/dl_writer.h"
#include "src/dl_writer_ascii.h"
#include <QList>
#include <QString>
#include <QFile>

class EntitiesDatas:public DL_CreationAdapter
{
public:
//    explicit EntitiesDatas();

    virtual void addPoint(const DL_PointData &d);
    virtual void addLine(const DL_LineData &d);
    virtual void addArc(const DL_ArcData &d);
    virtual void addCircle(const DL_CircleData &d);
    virtual void addEllipse(const DL_EllipseData &d);
    virtual void addText(const DL_TextData &d);
    virtual void addDimAngular(const DL_DimensionData &d, const DL_DimAngularData &d1);
//    virtual EntDimLinear(const DL_DimensionData &d, const DL_DimLinearData &d1){
//        qDebug(________________add deim linear";
//    }
    virtual void addMText(const DL_MTextData &d);
    virtual void addXLine(const DL_XLineData &);
    virtual void addRay(const DL_RayData &);
    virtual void addPolyline(const DL_PolylineData &d);
    virtual void addSpline(const DL_SplineData &);
    virtual void addComment(const std::string &);
    virtual void addVertex(const DL_VertexData &d);
    virtual void addLayer(const DL_LayerData &d);
    virtual void addXDataString(int, const std::string &);
    virtual void addXRecord(const std::string &);
    virtual void addTrace(const DL_TraceData &);
    virtual void endEntity();
    virtual void endSequence();
    virtual void setAttributes(const DL_Attributes &attrib);
    virtual void addHatch(const DL_HatchData &d);
    virtual void addHatchEdge(const DL_HatchEdgeData &d);

//    virtual void EntitiesDatas::att

    QList<DL_PointData> points;
    QList<DL_LineData> lines;//
    QList<DL_ArcData> arcs;
    QList<DL_CircleData> circles;//
    QList<DL_EllipseData> ellipses;
    QList<DL_TextData> texts;
    QList<DL_DimAngularData> dimangulars;
    QList<DL_DimLinearData> dimlines;
    QList<DL_DimRadialData> radias;
    QList<DL_VertexData> vertices;//
    QList<DL_PolylineData> polylines;//
    QList<DL_MTextData> mtexts;//
    QList<DL_HatchData> hatches;//
    QList<DL_HatchEdgeData> hatchedges;//
    QList<QString> hatchcolors;
};
#if 0
void EntitiesDatas::addLine(const DL_LineData& d)
{
 std::cout << "Line: " << d.x1 << "/" << d.y1
 << " " << d.x2 << "/" << d.y2 << std::endl;
}
#endif
void EntitiesDatas::addPoint(const DL_PointData &d){
    points.append(d);
    qDebug()<<"add point"<< d.x << "/" << d.y;
}
void EntitiesDatas::addLine(const DL_LineData &d){
    lines.append(d);
    qDebug()<<"add line";
}
 void EntitiesDatas::addArc(const DL_ArcData &d){
    arcs.append(d);
    qDebug()<<"add arc";
}
 void EntitiesDatas::addCircle(const DL_CircleData &d){
    circles.append(d);
    qDebug()<<"add circle"<<d.cx<<d.cy<<d.radius;
}
 void EntitiesDatas::addEllipse(const DL_EllipseData &d){
    ellipses.append(d);
    qDebug()<<"add ellipse";
}
 void EntitiesDatas::addText(const DL_TextData &d){
    texts.append(d);
    qDebug()<<"add text";
}
 void EntitiesDatas::addDimAngular(const DL_DimensionData &d, const DL_DimAngularData &d1){
    qDebug()<<"add angular";
}
//    virtual EntitiesDatas::addDimLinear(const DL_DimensionData &d, const DL_DimLinearData &d1){
//        qDebug()<<"___________________________add deim linear";
//    }
 void EntitiesDatas::addMText(const DL_MTextData &d){
    mtexts.append(d);
    qDebug()<<"add mtext";
}
 void EntitiesDatas::addXLine(const DL_XLineData &){
    qDebug()<<"add xline";
}
 void EntitiesDatas::addRay(const DL_RayData &){
    qDebug()<<"add ray";
}
 void EntitiesDatas::addPolyline(const DL_PolylineData &d){
    qDebug()<<"add polyline";
    polylines.append(d);
}
 void EntitiesDatas::addSpline(const DL_SplineData &){
    qDebug()<<"add spline data";
}
 void EntitiesDatas::addComment(const std::string &){
    qDebug()<<"add comment";
}
 void EntitiesDatas::addVertex(const DL_VertexData &d){
    vertices.append(d);
    qDebug()<<"add vertex";
}
 void EntitiesDatas::addLayer(const DL_LayerData &d){
    qDebug()<<"add layer";
    qDebug()<<QString::fromStdString(d.name);
}
 void EntitiesDatas::addXDataString(int, const std::string &){
    qDebug()<<"add xdata string";
}
 void EntitiesDatas::addXRecord(const std::string &){
    qDebug()<<"add repcord";
}
 void EntitiesDatas::addTrace(const DL_TraceData &){
    qDebug()<<"add trace";
}
 void EntitiesDatas::endEntity(){
    qDebug()<<"end entity";
    qDebug()<<"attribute"<<this->getAttributes().getColor();
}
 void EntitiesDatas::endSequence(){
    qDebug()<<"end sequence ";
}
 void EntitiesDatas::setAttributes(const DL_Attributes &attrib){
    qDebug()<<"set attribute";
}
 void EntitiesDatas::addHatch(const DL_HatchData &d){
    qDebug()<<"add hatch";
    hatches.append(d);
}
 void EntitiesDatas::addHatchEdge(const DL_HatchEdgeData &d){
    qDebug()<<"add hat edge data";
    hatchedges.append(d);
    if(this->getAttributes().getColor()==1){
        QString color="#ef3312";
        hatchcolors.append(color);
    }
    else if(this->getAttributes().getColor()==2){
        QString color="#efef33";
        hatchcolors.append(color);
    }
    else if(this->getAttributes().getColor()==3){
        QString color="#12ef33";
        hatchcolors.append(color);
    }
    else {
        QString color="#efefef";
        hatchcolors.append(color);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("myfile.dxf");
    if(file.exists())
    {
        file.remove();
        qDebug()<<"DEL dxf";
    }

    /*
    EntitiesDatas f;

    DL_Dxf dxf;
    //读取.dxf文件
    if (!dxf.in("r12.dxf", &f)) {
     std::cerr << "drawing.dxf could not be opened.\n";
    }
*/
#if 1

    DL_Dxf dxf;
    DL_Codes::version exportVersion = DL_Codes::AC1015;
    DL_WriterA* dw = dxf.out("myfile.dxf", exportVersion);
    if (dw==NULL)
    {
        printf("Cannot open file 'myfile.dxf' \
            for writing.");
        // abort function e.g. with return
    }

#if 1
    // int variable:
    //单位
    dw->dxfString(9, "$INSUNITS");
    dw->dxfInt(70, 4);
    // real (double, float) variable:
    dw->dxfString(9, "$DIMEXE");
    dw->dxfReal(40, 1.25);
    // string variable:
    dw->dxfString(9, "$TEXTSTYLE");
    dw->dxfString(7, "Standard");
    // vector variable:
    dw->dxfString(9, "$LIMMIN");
    dw->dxfReal(10, 0.0);
    dw->dxfReal(20, 0.0);
#endif
    //关闭header
    dw->sectionEnd();

    //写tablesection
    //.1 打开tables section
    dw->sectionTables();
    //.2 写viewports
    dxf.writeVPort(*dw);
    //.3写linetypes
    dw->tableLinetypes(25);

    dxf.writeLinetype(*dw, DL_LinetypeData("BYBLOCK","",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("BYLAYER","",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("CONTINUOUS","",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("ACAD_ISO02W100", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("ACAD_ISO03W100", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("ACAD_ISO04W100", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("ACAD_ISO05W100", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("BORDER", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("BORDER2", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("BORDERX2", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("CENTER", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("CENTER2", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("CENTERX2", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("DASHDOT", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("DASHDOT2", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("DASHDOTX2", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("DASHED", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("DASHED2", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("DASHEDX2", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("DIVIDE", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("DIVIDE2", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("DIVIDEX2","",0,0, 0));
    dxf.writeLinetype(*dw, DL_LinetypeData("DOT", "",0,0,0));
    dxf.writeLinetype(*dw, DL_LinetypeData("DOT2","",0,0, 0));
    dxf.writeLinetype(*dw, DL_LinetypeData("DOTX2", "",0,0,0));

    dw->tableEnd();

    //.4写layers 0不可以省略
    int numberOfLayers = 3;

    dw->tableLayers(numberOfLayers);

    dxf.writeLayer(*dw,
        DL_LayerData("0", 0),
        DL_Attributes( std::string(""),
                       DL_Codes::red,
                       -1,
                       100,
                       "BYLAYER"
                       ));     // default line style
    /*
    DL_Attributes(
        std::string(""),      // leave empty
        DL_Codes::black,        // default color
        100,                  // default width
        "CONTINUOUS")
*/
/*
    dxf.writeLayer(*dw,
        DL_LayerData("mainlayer", 0),
        DL_Attributes(
            std::string(""),
            DL_Codes::red,
            100,
            "BYLAYER"));//CONTINUOUS
*/
    dxf.writeLayer(*dw,
        DL_LayerData("mainlayer", 0),
        DL_Attributes());//CONTINUOUS

    dxf.writeLayer(*dw,
        DL_LayerData("anotherlayer", 0),
        DL_Attributes());

    dw->tableEnd();
    //.5其他tables 不必要
  //  dxf.writeStyle(*dw,DL_StyleData());
#if 0
    dxf.writeView(*dw);
    dxf.writeUcs(*dw);

    dw->tableAppid(1);
    dw->tableAppidEntry(0x12);
    dw->dxfString(2, "ACAD");
    dw->dxfInt(70, 0);
    dw->tableEnd();
   #endif
    //。6写dimension styles
    dxf.writeDimStyle(*dw,
                      1,
                      1,
                      1,
                      1,
                      1);

    dxf.writeBlockRecord(*dw);
#if 1
    dxf.writeBlockRecord(*dw, "myblock1");
    dxf.writeBlockRecord(*dw, "myblock2");
#endif
    dw->tableEnd();
    //.7结束tables section
    dw->sectionEnd();
    //写blocks section
    dw->sectionBlocks();

    dxf.writeBlock(*dw,
        DL_BlockData("*Model_Space", 0, 0.0, 0.0, 0.0));
    dxf.writeEndBlock(*dw, "*Model_Space");

    dxf.writeBlock(*dw,
        DL_BlockData("*Paper_Space", 0, 0.0, 0.0, 0.0));
    dxf.writeEndBlock(*dw, "*Paper_Space");

    dxf.writeBlock(*dw,
        DL_BlockData("*Paper_Space0", 0, 0.0, 0.0, 0.0));
    dxf.writeEndBlock(*dw, "*Paper_Space0");

    dxf.writeBlock(*dw,
        DL_BlockData("myblock1", 0, 0.0, 0.0, 0.0));

    // ...
    // write block entities e.g. with dxf.writeLine(), ..
    // ...
    dxf.writeEndBlock(*dw, "myblock1");

    dxf.writeBlock(*dw,
        DL_BlockData("myblock2", 0, 0.0, 0.0, 0.0));

    // ...
    // write block entities e.g. with dxf.writeLine(), ..
    // ...
    dxf.writeEndBlock(*dw, "myblock2");

    dw->sectionEnd();

    //写entities section
    dw->sectionEntities();

    // write all your entities..

    dxf.writePoint(*dw,
        DL_PointData(10.0, 45.0, 0.0),
        DL_Attributes());//"mainlayer", 256, -1, "BYLAYER"

    dxf.writeLine(*dw,
        DL_LineData(25.0, 30.0, 0.0,   // start point
                 100.0, 120.0, 0.0),   // end point
        //DL_Attributes("mainlayer", 256, -1, "BYLAYER"));
                  DL_Attributes());
    dxf.writeArc(*dw,
                 DL_ArcData(50.0,50.0,0.0,
                            20,0.0,20),
                 DL_Attributes(std::string(""),
                               DL_Codes::red,
                               -1,
                               100,
                               "BYLAYER"
                               ));

    dxf.writeCircle(*dw,DL_CircleData(50.0,50.0,0.0,20.0),
                    DL_Attributes(std::string(""),
                                  DL_Codes::red,
                                  -1,
                                  1,
                                  "BYLAYER"
                                  ));

    dw->sectionEnd();
    //写objects section
    dxf.writeObjects(*dw);
    dxf.writeObjectsEnd(*dw);
    //结束
    dw->dxfEOF();
    dw->close();
    delete dw;
#endif
    qDebug()<< "end"<<endl;
    return a.exec();
}
