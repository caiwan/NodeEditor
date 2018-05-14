#pragma once
#include <nodes/internal/NodeData.hpp>

namespace NodeEditor
{
	class DataPort : public QtNodes::NodeData
	{
	public:
		explicit DataPort(const QtNodes::NodeDataType& nodeDataType);

	    DataPort(const DataPort& other);

	    DataPort(DataPort&& other) noexcept;

	    DataPort& operator=(const DataPort& other);

	    DataPort& operator=(DataPort&& other) noexcept;

	    ~DataPort() override;

		QtNodes::NodeDataType type() const override { return m_nodeDataType; };
	 private:
		QtNodes::NodeDataType m_nodeDataType;
	};
}
