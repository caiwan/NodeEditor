#pragma once 

#include <nodes/NodeDataModel>

class DataPort;

class DataModel : public QtNodes::NodeDataModel{

public:

DataModel();
~DataModel();

// overrides - schema
  QString
  caption() const override
  { return m_caption; }

  bool
  captionVisible() const override { return m_isCaptionVisible; }

  QString
  name() const override
  { return m_name; }

// overrides - ports 
  unsigned int
  nPorts(PortType portType) const override;

  NodeDataType
  dataType(PortType portType, PortIndex portIndex) const override;

  std::shared_ptr<NodeData>
  outData(PortIndex port) override;

  // 
  void AddInput(DataPort* const& port);
  void AddOutput(DataPort* const& port);

// ... 

private:
QString m_caption;
bool m_isCaptionVisible;
QString m_name;

QList <DataPort*> m_inputs;
QList <DataPort*> m_outputs;

};
