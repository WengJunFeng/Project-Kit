#ifndef DL_CREATIONINTERFACE_H
#define DL_CREATIONINTERFACE_H

#include <string.h>

#include "dl_attributes.h"
#include "dl_codes.h"
#include "dl_entities.h"
#include "dl_extrusion.h"

class DL_CreationInterface {
public:
    DL_CreationInterface() {
        extrusion = new DL_Extrusion;
    }
    virtual ~DL_CreationInterface() {
        delete extrusion;
    }

    virtual void addLayer(const DL_LayerData& data) = 0;
    virtual void addBlock(const DL_BlockData& data) = 0;
    virtual void endBlock() = 0;
    virtual void addPoint(const DL_PointData& data) = 0;
    virtual void addLine(const DL_LineData& data) = 0;
    virtual void addArc(const DL_ArcData& data) = 0;
    virtual void addCircle(const DL_CircleData& data) = 0;
    virtual void addEllipse(const DL_EllipseData& data) = 0;
    virtual void addPolyline(const DL_PolylineData& data) = 0;
    virtual void addVertex(const DL_VertexData& data) = 0;
    virtual void addSpline(const DL_SplineData& data) = 0;
    virtual void addControlPoint(const DL_ControlPointData& data) = 0;
    virtual void addKnot(const DL_KnotData& data) = 0;
    virtual void addInsert(const DL_InsertData& data) = 0;
    virtual void addTrace(const DL_TraceData& data) = 0;
    virtual void add3dFace(const DL_3dFaceData& data) = 0;
    virtual void addSolid(const DL_SolidData& data) = 0;
    virtual void addMText(const DL_MTextData& data) = 0;
    virtual void addMTextChunk(const char* text) = 0;
    virtual void addText(const DL_TextData& data) = 0;
    virtual void addDimAlign(const DL_DimensionData& data,
                             const DL_DimAlignedData& edata) = 0;
    virtual void addDimLinear(const DL_DimensionData& data,
                              const DL_DimLinearData& edata) = 0;
    virtual void addDimRadial(const DL_DimensionData& data,
                              const DL_DimRadialData& edata) = 0;
    virtual void addDimDiametric(const DL_DimensionData& data,
                              const DL_DimDiametricData& edata) = 0;
    virtual void addDimAngular(const DL_DimensionData& data,
                              const DL_DimAngularData& edata) = 0;
    virtual void addDimAngular3P(const DL_DimensionData& data,
                              const DL_DimAngular3PData& edata) = 0;
    virtual void addDimOrdinate(const DL_DimensionData& data,
                             const DL_DimOrdinateData& edata) = 0;
    virtual void addLeader(const DL_LeaderData& data) = 0;
    virtual void addLeaderVertex(const DL_LeaderVertexData& data) = 0;
    virtual void addHatch(const DL_HatchData& data) = 0;
    virtual void addImage(const DL_ImageData& data) = 0;
	virtual void linkImage(const DL_ImageDefData& data) = 0;
    virtual void addHatchLoop(const DL_HatchLoopData& data) = 0;
    virtual void addHatchEdge(const DL_HatchEdgeData& data) = 0;
    virtual void endEntity() = 0;
    virtual void addComment(const char* comment) = 0;
    virtual void setVariableVector(const char* key, 
	               double v1, double v2, double v3, int code) = 0;
    virtual void setVariableString(const char* key, const char* value, int code) = 0;
    virtual void setVariableInt(const char* key, int value, int code) = 0;
    virtual void setVariableDouble(const char* key, double value, int code) = 0;
     virtual void endSequence() = 0;
    void setAttributes(const WUDXFAttribute& attrib) {
        attributes = attrib;
    }
    WUDXFAttribute getAttributes() {
        return attributes;
    }
    void setExtrusion(double dx, double dy, double dz, double elevation) {
        extrusion->setDirection(dx, dy, dz);
		extrusion->setElevation(elevation);
    }
    DL_Extrusion* getExtrusion() {
        return extrusion;
    }

protected:
    WUDXFAttribute attributes;
    DL_Extrusion *extrusion;
};

#endif
